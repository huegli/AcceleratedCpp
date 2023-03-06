#include<algorithm>
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::equal;
using std::string;

bool is_palindrome(const string& s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

int main() {

    if (is_palindrome("civic"))
        cout << "'civic' is a palindrome" << endl;
    if (is_palindrome("level"))
        cout << "'level' is a palindrome" << endl;
    if (is_palindrome("hurga"))
        cout << "'hurga' is not a palindrome" <<  endl;

    return 0;
}
