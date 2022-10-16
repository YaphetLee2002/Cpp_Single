#include<iostream>
using namespace std;
int main()
{
    int chest = 42;
    int waist = 42;
    int inseam = 42;
    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex;          //修改cout显示整数的方式为十六进制
    cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
    cout << oct;          //修改cout显示整数的方式为八进制
    cout << "inseam = " << inseam << "(octal for 42)" << endl;
    return 0;
}