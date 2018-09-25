#include "student_info.h"


using std::vector; 
using std::istream; 
using std::string;
using std::endl;
using std::back_inserter;


Student_info::Student_info(): midterm(0), final(0) {}

Student_info::Student_info(istream& is) {read(is);}

istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const
{
    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return  s1.name() < s2.name();
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if(in)
    {
        hw.clear();
        double x;
        while(in >> x)
            hw.push_back(x);
        
        in.clear();
    }
    return in;
}