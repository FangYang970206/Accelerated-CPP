#include <iostream>
#include <vector>
#include <algorithm>

#include "student_info.h"
#include "readfile.h"
#include "median.h"
#include "grade.h"

using namespace std;


template <class Function>
double tem_analysis(const vector<Student_info>& students, Function func)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), func);
    return median(grades);
}


int main()
{
    vector<Student_info> did, didnt, students;
    ifstream file("test.txt");
    read(file, students);
    for(vector<Student_info>::iterator it = students.begin(); it != students.end(); it++){
        if(did_all_hw(*it)){
            did.push_back(*it);
        }else{
            didnt.push_back(*it);
        }
    }
    if(did.empty()){
        cout << "no student did all the homework" << endl;
        return 1;
    }
    if(didnt.empty()){
        cout << "every student did all the homework" << endl;
        return 1;
    }
    cout << "median did: " << tem_analysis(did, grade_aux) << "  "
         << "median didnt: " << tem_analysis(didnt, grade_aux) << endl;
    cout << "average did: " << tem_analysis(did, average_grade) << "  "
         << "average didnt: " << tem_analysis(didnt, average_grade) << endl;
    cout << "optimistic_median did: " << tem_analysis(did, optimistic_median) << "  "
         << "optimistic_median didnt: " << tem_analysis(didnt, optimistic_median) << endl;
    
    system("pause");
    return 0;
}