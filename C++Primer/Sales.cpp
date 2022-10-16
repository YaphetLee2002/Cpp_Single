#include <iostream>
#include <fstream>
#include <string>

class Sales_data
{

    //为Sales_data非成员函数所做的友元声明
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

public:
    //构造函数，定义在类内
    //Sales_data() = default;                         //C++11中，若果需要默认行为，可以加上 = default
    Sales_data(std::string s, unsigned cnt, double rev) : bookNo(s), unit_sold(cnt), revenue(rev * cnt) {}
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::string s) : Sales_data(s, 0, 0) {}
    Sales_data(std::istream &is) { read(is, *this); } //委托构造函数 C++11

    //关于Sales_data对象的操作，为Sales_data类的成员函数
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const
    {
        return unit_sold ? revenue / unit_sold : 0;
    }
    //数据成员
    std::string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

//Sales_data接口的非成员组成部分的声明
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

/*
Sales_data::Sales_data(std::istream &is) //定义在类外部的构造函数
{
    read(is, *this); //从is中读取一条信息然后存入this对象中
}
*/
/*
double Sales_data::avg_price() const
{
    if (unit_sold)
        return revenue / unit_sold;
    else
        return 0;
}
*/
//返回一个指向Sales_data对象，隐式声明的this指针
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    unit_sold += rhs.unit_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.unit_sold >> price;
    item.revenue = price * item.unit_sold;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.unit_sold << " "
       << item.revenue << " " << item.avg_price();
    return os;
}

//调用两个Sales_data对象，返回Sales_data对象，为二者的和
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs; //使用lhs的副本拷贝至sum，sum的数据成员将与lhs一致
    sum.combine(rhs);
    return sum;
}

int main(int argc, char const *argv[])
{
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(std::cin, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
}