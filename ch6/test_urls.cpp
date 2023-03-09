#include <iostream>
#include <string>
#include <vector>
#include "urls.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {

    string s = "bla, bla, check out http://google.com and https://kde.org";

    vector v = find_urls(s);

    for (auto s : v) {
        cout << s << endl;
    }
}
