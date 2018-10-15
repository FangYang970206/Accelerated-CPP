#pragma once

#include "Core.h"


class student_pass : public Core{
    public:
        student_pass() {};
        student_pass(std::istream& is) {read(is);}
        double grade() const;
        bool ispass() const;
        student_pass* clone() const {return new student_pass(*this);}
};