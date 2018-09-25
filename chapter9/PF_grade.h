#ifndef __PF_GRADE_H_
#define __PF_GRADE_H_

#include <iostream>
#include <vector>
#include <string>

#include "PF_student_info.h"

class PF_grade{
    public:
        PF_grade() {};
        void add_student(PF_Student_info&);
        void print_grades();
    private:
        std::vector<PF_Student_info> students;
};

bool ispass(const PF_Student_info&);

#endif