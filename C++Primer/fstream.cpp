#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    string infile = "test.txt";
    vector<string> vec;
    ifstream in(infile);
    if(in)
    {
        string buf;
        while (getline(in, buf))
        {
            vec.push_back(buf);
        }
    }
    else
    {
        cerr << "cannot open this file: " << infile << endl;
    }
    for (auto &&i : vec)
    {
        cout << i << endl;
    }
    
    
    return 0;
}
