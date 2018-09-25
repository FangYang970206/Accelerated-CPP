#ifndef _PF_STUDENT_INFO_H_
#define _PF_STUDENT_INFO_H_


#include <iostream>
#include <string>
#include <vector>

class PF_Student_info{
    public:
        PF_Student_info() : midterm(0), final(0){}
        PF_Student_info(std::istream& is){read(is);}
        std::istream& read(std::istream&);
        char grade() const;
        std::string name() const;
    private:
        std::string n;
        double midterm, final;
};

bool compare(const PF_Student_info&, const PF_Student_info&);



#endif