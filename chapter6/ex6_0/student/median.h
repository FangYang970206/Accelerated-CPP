#ifndef _MEDIAN_H_
#define _MEDIAN_H_

#include <vector>
#include "student_info.h"

double median(std::vector<double>);
double median_analysis(const std::vector<Student_info> &);
double average(const std::vector<double> &);
double average_analysis(const Student_info &);
double optimistic_median(const Student_info&);
double average_analysis(const std::vector<Student_info> & students);
double optimistic_median_analysis(const std::vector<Student_info> & students);

#endif