#include <algorithm>
#include "student_info.h"
#include "grade.h"


using std::vector; 
using std::istream;
using std::find;   
using std::endl;
using std::remove_copy_if;
using std::remove_if;
using std::back_inserter;
using std::list;


bool compare(const Student_info& s1, const Student_info& s2)
{
    return  s1.name < s2.name;
}

bool did_all_hw(const Student_info& s){
    return ((find(s.homework.begin(), s.homework.end(), 0)) == (s.homework.end()));
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

vector<Student_info> extract_fails_1(vector<Student_info>& students)
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

vector<Student_info> extract_fails_2(vector<Student_info>& students){
    vector<Student_info> fails;
    remove_copy_if(students.begin(), students.end(), back_inserter(fails), pgrade);
    students.erase(remove_if(students.begin(), students.end(), pgrade), students.end());
    return fails;
}

vector<Student_info> extract_fails_3(vector<Student_info>& students){
    vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
    vector<Student_info> fails(iter, students.end());
    students.erase(iter, students.end());
    return fails;
}

list<Student_info> extract_fails_4(list<Student_info>& students)
{
    list<Student_info> fails;
    list<Student_info>::iterator it = students.begin();
    while(it != students.end())
    {
        if(fgrade(*it)){
            fails.push_back(*it);
            it = students.erase(it);
        }else{
            it++;
        }
    }
    
    return fails;
}

void write_analysis(std::ostream& out, const std::string& name, 
                    double analysis(const std::vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt){
                        out << name << ": median(did) =" << analysis(did) <<
                                       ": median(didnt) = " << analysis(didnt) << endl;
                    }