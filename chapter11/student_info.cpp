#include <algorithm>
#include "student_info.h"


using std::cout;
using std::vector; 
using std::istream; 
using std::string;
using std::endl;
using std::back_inserter;
using std::find;


Student_info& Student_info::operator=(const Student_info& other){
    print("assign");
    if(this != &other)
        clone(other);
    return *this;
}

void Student_info::clone(const Student_info & other){
    n = other.n;
    midterm = other.midterm;
    final = other.final;
    homework = other.homework;
}

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

void Student_info::print(const string & s){
    cout << s << endl;
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

bool did_all_hw(const Student_info& s){
    return ((find(s.homework.begin(), s.homework.end(), 0)) == (s.homework.end()));
}

void write_analysis(std::ostream& out, const std::string& name, 
                    double analysis(const std::vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt){
                        out << name << ": median(did) =" << analysis(did) <<
                                       ": median(didnt) = " << analysis(didnt) << endl;
                    }