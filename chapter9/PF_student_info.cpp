#include "PF_student_info.h"


using namespace std;


istream& PF_Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

char PF_Student_info::grade() const
{
    return (midterm+final)/2 < 60 ? 'F' : 'P';
}

string PF_Student_info::name() const
{
    return n;
}

bool compare(const PF_Student_info& s1, const PF_Student_info& s2)
{
    return s1.name() < s2.name();
}