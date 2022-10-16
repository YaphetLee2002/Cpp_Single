#include<iostream>
#include<numeric> //定义了数值泛型算法
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;
int main(){
    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1)/sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), a2); //
    int sum = accumulate(begin(a1), end(a1), 0);
    vector<int> vec;
    auto it = back_inserter(vec);
    fill_n(back_inserter(vec), 10, 0);
    
}