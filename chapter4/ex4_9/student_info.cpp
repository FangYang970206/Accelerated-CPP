#include "student_info.h"
#include "grade.h"


using std::vector; using std::istream;
using std::string;

bool compare(const Student_info& s1, const Student_info& s2)
{
    return  s1.name < s2.name;
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

istream& read(istream& is , Student_info& s)
{   
    static string name;
    static double midterm, final;
    static vector<double> hw;
    is >> s.name >> midterm >> final;
    read_hw(is, hw);
    s.final_grade = grade(midterm, final, hw);
    return is;
}