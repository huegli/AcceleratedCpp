#include <iostream>
#include <string>
#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::vector;

int main() 
{
    string s;
    // read and split each line of input
    while (getline(cin, s)) {
        vector<string> v = split(s);

        // write each word in v
        for (auto i : v)
            cout << i << endl;
    }
    return 0;
}
