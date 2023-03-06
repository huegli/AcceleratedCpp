#include <iostream>
#include <string>
#include "split.h"
#include "char_pic.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() 
{
    vector<string> v1 = frame(split("Hello, world"));
    vector<string> v2 = frame(split("This is a test"));

    vector<string> v = vcat(v1, v2);
    for (auto i : frame(v)) 
        cout << i << endl;
    cout << endl;

    return 0;
}
