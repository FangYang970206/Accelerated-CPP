#include <algorithm>
#include <stdexcept>
#include "median.h"
#include "grade.h"

using std::sort; 
using std::vector;
using std::domain_error;
using std::transform;
using std::accumulate;
using std::back_inserter;
using std::remove_copy;
using std::stable_partition;
using std::string;


double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if(size==0)
        throw domain_error("median of empty vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size % 2 ==0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}

double median_analysis(const vector<Student_info> & students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const vector<double> & v){
    return accumulate(v.begin(), v.end(), 0.0)/v.size();
}

double average_grade(const Student_info& s){
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info> & students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double optimistic_median(const Student_info& s){
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
    if(nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info> & students){
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
    return median(grades);
}

/*
args:
    choose: 1 -> call median_analysis
            2 -> call average_analysis
            3 -> call optimistic_median_analysis
*/
double analysis(const vector<Student_info> & students, int choose){
    vector<double> grades;
    switch(choose){
        case 1:
            transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
            break;
        case 2:
            transform(students.begin(), students.end(), back_inserter(grades), average_grade);
            break;
        case 3:
            transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
            break;
        default:
            break;
    }
    return median(grades);
}

