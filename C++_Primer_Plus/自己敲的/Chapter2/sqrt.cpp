#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double area;
    cout << "Enter the floor area, in sqy=uare feet, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "That' s the equivalent of a square " << side
         << " feet to the side." << endl;
    cout << "How fancinating!" << endl;
    return 0;
}