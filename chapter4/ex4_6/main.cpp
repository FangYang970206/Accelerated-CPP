#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"

using std::cin;     using std::setprecision;
using std::cout;    using std::domain_error;
using std::sort;    using std::streamsize;
using std::endl;    using std::string;
using std::max;     using std::vector;
using std::setw;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type max_len = 0;

    while(read(cin, record))
    {
        max_len = max(max_len, record.name.size());
        students.push_back(record);
    }
    sort(students.begin(), students.end(), compare);
    for(vector<Student_info>::size_type i = 0; i != students.size(); i++)
    {   
        cout << setw(max_len+1) << students[i].name;

        try{
            double final_grade = students[i].final_grade;
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade 
                 << setprecision(prec);
        }catch (domain_error e){
            cout << e.what();
        }
    }
    system("pause");
    return 0;
}