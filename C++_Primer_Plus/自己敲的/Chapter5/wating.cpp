#include<iostream>
#include<ctime>
int main()
{
    using namespace std;
    cout << "Enter the delay time, in second: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting\a\n";
    clock_t start = clock();
    long long sum = 0;
    while (clock() - start < delay)
        sum++;
    cout << "done" << sum << ".\n";

    return 0;
}