#include<iostream>
#include<forward_list>
using namespace std;
int main(int argc, char const *argv[])
{
    forward_list<int> fist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = fist.before_begin();
    auto curr = fist.begin();
    while (curr != fist.end()) {
        if(*curr % 2)
            curr = fist.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }
    for (auto &&i : fist) {
        cout << i << " ";
    }
    return 0;
}