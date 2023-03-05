#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <list>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;
using std::list;

int main() {
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records and find the length of the longest name
    // Invariant: students contains all the student records read so far
    //              maxlen contains the length of the longest name in students
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    list<Student_info> failing_students =
        extract_fails(students);

    // alphabetize the records
    students.sort(compare);


    
    // write the names and grades
    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        // write the name, padded on the right to maxlen + 1 characters
        cout << iter->name
            << string(maxlen + 1 - iter->name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(*iter);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        ++iter;
        cout << endl;
    }
    return 0; 
}
