#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>


struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);


#endif