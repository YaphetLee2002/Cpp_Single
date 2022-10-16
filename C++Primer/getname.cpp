#include<iostream>
#include<cstring>
char * getname(void)
{
    using namespace std;
    char temp[80];
    cin >> temp;
    char * pn = new char [strlen(temp + 1)];
    strcpy(pn, temp);
    return pn;
}