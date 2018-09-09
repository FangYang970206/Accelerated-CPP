#ifndef _GRADE_H_
#define _GRADE_H_

#include <vector>
#include "student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(Student_info&);


#endif