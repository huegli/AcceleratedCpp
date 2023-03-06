#include <iostream>
#include <string>
#include "split.h"
#include "char_pic.h"

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

        for (auto i : frame(v)) 
            cout << i << endl;
        cout << endl;
    }
    return 0;
}
