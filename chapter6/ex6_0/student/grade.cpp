#include <stdexcept>
#include <vector>
#include "median.h"
#include "grade.h"

using std::domain_error;
using std::vector;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
    if(hw.size()==0)
        throw domain_error("student have done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(Student_info& s)
{
    return grade(s) < 60 ? true: false;
}

double grade_aux(const Student_info& s){
    try{
        return grade(s);
    }catch (domain_error){
        return grade(s.midterm, s.final, 0);
    }
}

bool pgrade(Student_info& s){
    return !fgrade(s);
}