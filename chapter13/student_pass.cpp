#include "student_pass.h"

double student_pass::grade() const
{
    if(!homework.empty())
        return Core::grade();
    else
        return (final + midterm)/2;
}

bool student_pass::ispass() const 
{
    return student_pass::grade() >= 60;
}