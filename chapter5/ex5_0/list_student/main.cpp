#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "student_info.h"

using std::cin;     using std::setprecision;
using std::cout;    using std::domain_error;
using std::sort;    using std::streamsize;
using std::endl;    using std::string;
using std::max;     using std::setw;    
using std::list;

int main()
{
    list<Student_info> students, fails;
    Student_info record;
    string::size_type max_len = 0;

    while(read(cin, record))
    {
        max_len = max(max_len, record.name.size());
        students.push_back(record);
    }
    students.sort(compare);
    fails = extract_fails(students);
    cout << "students final grade > 60: " << endl;
    for(list<Student_info>::iterator it = students.begin(); it != students.end(); it++)
    {   
        cout << setw(max_len) << (*it).name;
        cout << ": ";
        try{
            double final_grade = grade(*it);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade 
                 << setprecision(prec) << endl;
        }catch (domain_error e){
            cout << e.what();
        }
    }
    cout << "students final grade < 60: " << endl;
    for(list<Student_info>::iterator it = fails.begin(); it != fails.end(); it++)
    {   
        cout << setw(max_len) << (*it).name;
        cout << ": ";
        try{
            double final_grade = grade(*it);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade 
                 << setprecision(prec) << endl;
        }catch (domain_error e){
            cout << e.what();
        }
    }

    system("pause");
    return 0;
}