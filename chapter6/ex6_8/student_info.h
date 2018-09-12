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
bool did_all_hw(const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
void write_analysis(std::ostream&, const std::string&, 
                    double analysis(const std::vector<Student_info>&, int),
                    int,
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);
std::vector<Student_info> extract_fails_1(std::vector<Student_info>&); 
std::vector<Student_info> extract_fails_2(std::vector<Student_info>&); 
std::vector<Student_info> extract_fails_3(std::vector<Student_info>&);
std::list<Student_info> extract_fails_4(std::list<Student_info>&);
std::vector<Student_info> classify(std::vector<Student_info>&, bool criteria(const Student_info& ));



#endif