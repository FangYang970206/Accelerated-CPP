#include <stdexcept>
#include "median.h"
#include "grade.h"

using std::domain_error;

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
