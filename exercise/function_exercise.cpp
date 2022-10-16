#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isShort(const string &s1, const string &s2) //使用引用以避免拷贝
{
    return s1.size() < s2.size();
}

//使用引用形参返回额外信息，如本例中的&occurs
//本函数返回第一次出现字符c的位置(返回值)以及字符c的出现次数(引用形参)
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

//若s末尾为句号，那么它是一个句子
bool is_sentence(const string &s)
{
    string::size_type ctr = 0;
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

int (*func1(int n))[10];
auto func2(int i) -> int(*)[10];

string (&func3(string (&s)[10]))[10];
using ArrT = string[10];
ArrT& func4(ArrT& arr);
auto func5(ArrT& arr)->string(&)[10];
string S[10];
decltype(S)& func6(ArrT& arr);