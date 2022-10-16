#include<iostream>
const int ArSize (80);
int main(int argc, char const *argv[])
{
    using namespace std;
    char line[ArSize];
    int space = 0;

    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);
    cout << "Comlete line:\n" << line << endl;
    cout << "Line through first period:\n";
    for(int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];
        if(line[i] == '.')
            break;
        if(line[i] == ' ')
            space++;
        continue;
    }
    cout << "\n" << space << " spaces\n";
    cout << "Done." << endl;
    return 0;
}
