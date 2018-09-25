#include <algorithm>
#include "PF_grade.h"


using namespace std;


void PF_grade::add_student(PF_Student_info& s)
{
    students.push_back(s);
    partition(students.begin(), students.end(), ispass);
}

void PF_grade::print_grades()
{
    typedef vector<PF_Student_info>::const_iterator iter;
    
    for(iter it = students.begin(); it != students.end(); it++){
        cout << it->name() << ": " << it->grade() << endl; 
    }
}

bool ispass(const PF_Student_info& s)
{
    return s.grade() == 'P';
}