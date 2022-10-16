#include<iostream>
using namespace std;           //建议将std只放在需要的函数内
void simon(int);
int main()
{
    simon(3);
    cout << "Pick an integer: ";
    int count;
    cin >> count;
    simon (count);
    cout << "Done!" << endl;
    return 0;
}

void simon (int n){
    cout << "Simon says touch your toes " << n << " times." << endl;
}