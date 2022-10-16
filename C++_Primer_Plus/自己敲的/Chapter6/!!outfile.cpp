#include<iostream>
#include<fstream>

int main()
{
    using namespace std;

    char automobile[50];
    int year;
    double asking_price;
    double now_price;

    ofstream outFile;       //create object for output
    outFile.open("carinfo.txt");        //associate with a file

    cout << "Enter the make and nodel of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the mobile year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> asking_price;
    now_price = 0.913 * asking_price;

//display information on screen with cout

    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << asking_price << endl;
    cout << "Now asking $" << now_price << endl;


//now exact same things using outFile instead of cout

    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << asking_price << endl;
    outFile << "Now asking $" << now_price << endl;
    
    outFile.close();
    return 0;
}