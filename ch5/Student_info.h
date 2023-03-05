#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info header file
#include <iostream>
#include <list>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
bool fgrade(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif

