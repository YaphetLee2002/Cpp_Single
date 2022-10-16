#include <iostream>
#include <iterator>
#include <cstddef>
using int_array = int[4];
typedef int int_array[4]; //两种完全一样的声明
using namespace std;
int main()
{
    constexpr int sz = 42;
    int_array m = {0, 1, 2, 3}; //使用using类型别名使声明更清楚
    for (auto i : m)
        cout << i << " ";
    cout << endl;

    int arr[sz] = {};
    int ia[3][4] = {};                  //一个二维数组
    int(&rowr)[4] = ia[1];              //把rowr绑定到ia的第二个4元素数组上
    int length = begin(arr) - end(arr); //length代表数组场电影
    int *arrp[sz] = {};                 //一个包含sz个int型指针的数组
    int *pbeg = begin(arr);
    int *pend = end(arr);
    int(*Parray)[sz] = &arr; //Parray指向一个含有sz个整数的数组
    int(&arrRef)[sz] = arr;  //arrRef引用一个含有sz个整数的数组
    int *(&arry)[sz] = arrp; //arry是一个数组的引用，该数组含有sz个指针

    const size_t rowCnt = 3, colCnt = 4;
    size_t cnt(0);
    for (auto &row : ia)
        for (auto &col : row)
            col = cnt++;

    for (auto &i : ia) //除最内层循环以外都要使用引用类型
        for (auto j : i)
            cout << j << endl;

    return 0;
}