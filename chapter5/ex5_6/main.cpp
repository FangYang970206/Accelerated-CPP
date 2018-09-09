#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include "grade.h"
#include "student_info.h"
#include "readfile.h"


using std::cin;     using std::cout;    
using std::endl;    using std::string;
using std::vector;  using std::ifstream;  


int main()
{
    vector<Student_info> students, fails;
    ifstream file_10000("10000.txt");
    read(file_10000, students);
    vector<Student_info>::size_type raw_size = students.size();
    cout << "the method 1(erase) cost: " ;
    DWORD start_time = GetTickCount();
    fails = extract_fails_del(students);
    DWORD end_time = GetTickCount();
    cout << end_time - start_time << "ms" << endl;

    cout << "the method 2(insert) cost: " ;
    start_time = GetTickCount();
    fails = extract_fails_insert(students);
    students.resize(raw_size - fails.size());
    end_time = GetTickCount();
    cout << end_time - start_time << "ms" << endl;

    system("pause");
    return 0;
}