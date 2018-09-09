#include "student_info.h"
#include "grade.h"


using std::vector; using std::istream;

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
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fails;
    vector<Student_info>::size_type i=0;
    while(i != students.size())
    {
        if(fgrade(students[i])){
            fails.push_back(students[i]);
            students.erase(students.begin() + i);
        } else{
            i++;
        }
    }
    return fails;
}