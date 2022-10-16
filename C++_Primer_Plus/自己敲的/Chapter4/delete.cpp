#include<iostream>
#include<cstring>
using namespace std;
char * getname(void){
    char temp[80];

    cout << "Enter the last name: ";
    cin >> temp;
    char * pn = new char [strlen(temp) + 1];
    strcpy(pn, temp);

    return pn;
}
int main(int argc, char const *argv[])
{
    char * name;
    name = getname();
    cout << name << " at " << (int*)name << endl;
    delete [] name;
    
    name = getname();
    cout << name << " at " << (int*)name << endl;
    delete [] name;

    return 0;
}

