#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"
#include "Core.h"

class Student_check{
    public:
        Student_check() {}
        Student_check(std::string& s) {n = s;}
        double get_grade(std::vector<Student_info>& vec){
            for(auto s : vec){
                if(n == s.name())
                    return s.grade();
            }
        }
        std::string name() const {return n;}
    private:
        std::string n;
};