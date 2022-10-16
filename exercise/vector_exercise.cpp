#include<iostream>
#include<cstdio>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
    vector<unsigned> score(11, 0);
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(begin(int_arr), end(int_arr));
    for (auto i : ivec)
        cout << i << " ";
    cout << endl;

    unsigned grade;
    auto it = score.begin();
    cout << "输入成绩并以ctrl+Z结束:";
    while(cin >> grade)
        if(grade <= 100)
            ++*(it + grade / 10);
    for (auto i : score)
        cout << i << " ";
    
    return 0;
}