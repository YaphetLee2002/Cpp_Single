#include<iostream>
int main()
{
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter character; enter \"#\" to quit: " << endl;
    cin >> ch;
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin >> ch;
    }
    cout << endl << count << " charaters read.\n";
    return 0;
}