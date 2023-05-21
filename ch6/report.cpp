#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <list>
#include <string>
#include <vector>
#include "Student_info.h"
#include "analysis.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::list;

int main() {
    vector<Student_info> did, didnt;
    Student_info student;
    string::size_type maxlen = 0;

    // read and store all the records and find the length of the longest name
    // Invariant: students contains all the student records read so far
    //              maxlen contains the length of the longest name in students
    while (read(cin, student)) {
        maxlen = max(maxlen, student.name.size());
        
        // seperate whether homework was done
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
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

    // do the analysises
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0; 
}
