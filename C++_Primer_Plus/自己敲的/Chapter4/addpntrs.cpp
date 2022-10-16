#include<iostream>
int main()
{
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    double * pw = wages;
    short * ps = &stacks[0];

    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw++;
    cout << "add 1 to the pw pointer: " << endl;
    cout << "pw = " << pw << ", *pw = " << *pw << endl << endl;

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps++;
    cout << "add 1 to the ps pointer: " << endl;
    cout << "ps = " << ps << ", *ps = " << *ps << endl << endl;
    return 0;
}