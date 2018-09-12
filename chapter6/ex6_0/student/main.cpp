#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <windows.h>
#include "median.h"
#include "grade.h"
#include "student_info.h"
#include "readfile.h"

    
using std::cout;    using std::domain_error;
using std::sort;    using std::streamsize;
using std::endl;    using std::string;
using std::max;     using std::vector;
using std::cin;     using std::ifstream;
using std::list;


int main()
{
    vector<Student_info> did, didnt, students;
    ifstream file("test.txt");
    ifstream file_10000("10000.txt");
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
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "optimistic_median", optimistic_median_analysis, did, didnt);
    students.clear();
    read(file_10000, students);
    vector<Student_info> students_backup1 = students, students_backup2= students;
    list<Student_info> l_students;
    read(file_10000, l_students);
    cout << "test differet extract_fails function" << endl;

    cout << "extract_fails_1 runtime: ";
    DWORD start_time = GetTickCount();
    extract_fails_1(students);         //not bad
    DWORD end_time = GetTickCount();
    cout << end_time - start_time << "ms" << endl;

    cout << "extract_fails_2 runtime: ";
    start_time = GetTickCount();
    extract_fails_2(students_backup1); //not good
    end_time = GetTickCount();
    cout << end_time - start_time << "ms" << endl;

    cout << "extract_fails_3 runtime: ";
    start_time = GetTickCount();
    extract_fails_3(students_backup2); //good
    end_time = GetTickCount();
    cout << end_time - start_time << "ms" << endl;

    cout << "extract_fails_4 runtime: ";
    start_time = GetTickCount();
    extract_fails_4(l_students);       //very good
    end_time = GetTickCount();
    cout << end_time - start_time << "ms" << endl;

    system("pause");
    return 0;
}