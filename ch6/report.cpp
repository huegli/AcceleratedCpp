#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <list>
#include <string>
#include <vector>
#include "Student_info.h"
#include "median.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::list;

int main() {
    vector<Student_info> did, didnt;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records and find the length of the longest name
    // Invariant: students contains all the student records read so far
    //              maxlen contains the length of the longest name in students
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        
        // seperate whether homework was done
        if (did_all_hw(record))
            did.push_back(record);
        else
            didnt.push_back(record);
    }

    // check that both groups contain data
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);

    return 0; 
}
