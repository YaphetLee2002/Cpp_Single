#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v(10, 1);
    v.resize(9, 2); //先调整尺寸，之后将空缺的位置填补为第二个参数
    for (auto &&i : v){
        cout << i << " ";
    }
    return 0;
}