#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s("hello world!!!");
	const char *str = s.c_str(); //必须为常量const
	cout << str << endl;
	decltype(s.size()) punct_cnt = 0; //punct_cnt的类型与s.size()相同

	for (auto c : s)
		if (ispunct(c))
			++punct_cnt;
	cout << punct_cnt << endl;

	if (!s.empty()) //第一个字母大写
		s[0] = toupper(s[0]);
	cout << s << endl;

	if(s.begin() != s.end()) // 使用迭代器的第一个字母大写
	{
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s << endl;
	
	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index) //isspace用于判断遇到空白
		s[index] = toupper(s[index]);													 //第一个单词大写
	cout << s << endl;

	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) //使用迭代器的第一个单词大写
		*it = toupper(*it);
	cout << s << endl;

	for (auto &c : s) //全部大写
		c = toupper(c);
	cout << s << endl;

	return 0;
}