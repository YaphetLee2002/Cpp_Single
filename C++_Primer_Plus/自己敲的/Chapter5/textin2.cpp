#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;

    cout << "Enter characters; enter\"#\" to quit: " << endl;
    cin.get(ch);
    while(ch != '#')
    {
        cout << ch;
        ++count;
        cin.get(ch); //use it again
    }
    cout << endl << count << " charaters read\n";
    return 0;
}