// source file for the median function
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>
#include "grade.h"
#include "analysis.h"

using std::domain_error;    using std::sort;    using std::vector;
using std::accumulate;
using std::back_inserter;
using std::remove_copy;
using std::transform;

// compute the median of a vector<double>
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size/2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

// this version works fine
double median_analysis(const vector<Student_info>& students) 
{
    vector<double> grades;

    transform(students.begin(), students.end(),
            back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const vector<double> v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
            back_inserter(grades), average_grade);
    return median(grades);
}

// median of the nonzero elements of s.homework or 0 if no such elemest exist
double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
            back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;

    transform(students.begin(), students.end(),
            back_inserter(grades), optimistic_median);
    return median(grades);
}

