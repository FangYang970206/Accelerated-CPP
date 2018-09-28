#ifndef _STUDENT_INFO_H_
#define _STUDENT_INFO_H_

#include <iostream>
#include <string>

#include <vector>

class Student_info {
    public: 
        std::string n;
        double midterm, final;
        std::vector<double> homework;
        Student_info() {print("create");}
        Student_info(std::istream& is) {
                read(is);
                print("create");
            }
        Student_info(const Student_info& s) {
                print("copy");
                clone(s);
            }
        Student_info& operator=(const Student_info&);
        ~Student_info() {print("destory");};
        double grade() const;
        bool valid() const {return !homework.empty();}
        std::istream& read(std::istream&);
        std::string name() const {return n;}
    private:
        void print(const std::string &);
        void clone(const Student_info&);
        
};

bool did_all_hw(const Student_info& );
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double, double, const std::vector<double>&);
bool compare(const Student_info&, const Student_info&);
void write_analysis(std::ostream&, const std::string&, 
                    double analysis(const std::vector<Student_info>&),
                    const std::vector<Student_info>&,
                    const std::vector<Student_info>&);


#endif