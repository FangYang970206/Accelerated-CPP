#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>


class Student_info {
    public: 
        Student_info();
        Student_info(std::istream&);
        double grade() const;
        bool valid() const {return !homework.empty();}
        std::istream& read(std::istream&);
        std::string name() const {return n;}
    private:
        std::string n;
        double midterm, final, g;
        std::vector<double> homework;
};


std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double, double, const std::vector<double>&);
bool compare(const Student_info&, const Student_info&);


#endif