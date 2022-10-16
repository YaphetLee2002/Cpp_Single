#include<iostream>
using namespace std;
int main()
{
    unsigned quiz1 = 0;
    quiz1 |= 1UL << 27; //Student 27 passed the test
    quiz1 &= ~(1UL << 27); //Student 27 didn' t passed the test
    bool status = quiz1 & (1UL << 27); //Check student 27 passed the test
}