#include<iostream>
const int ArSize = 8;
int sum_arr(int [], int);
int main(int argc, char const *argv[])
{
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << cookies << " = array address." << endl;
    cout << sizeof(cookies)<< " = sizeof(cookies)." << endl; 
    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten " << sum << " cookies." << endl;
    sum = sum_arr(cookies, 3);
    
    return 0;
}
