// source file for Student_info-related functions
#include "Student_info.h"
#include "grade.h"

using std::istream;     using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// seperate passing and failing student records, first try
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> pass, fail;
    vector<Student_info>::iterator iter = students.begin();

    // invariant: elements [0, i) of students represent passing grades
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

istream& read(istream& is, Student_info& s)
{
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    
    read_hw(is, s.homework);    // read and store all the student's homework grades
    return is;
} 

