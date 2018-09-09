#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <windows.h>
#include "grade.h"
#include "student_info.h"
#include "split.h"
#include "readfile.h"


using std::cin;       using std::cout;      
using std::endl;      using std::string;  
using std::list;      using std::vector;
using std::ifstream;  using std::cerr;


int main()
{
    list<Student_info> list_students, list_fails;
    vector<Student_info> vec_students, vec_fails;
    ifstream file_100("100.txt");
    ifstream file_1000("1000.txt");
    ifstream file_10000("10000.txt");
    Student_info record;
    string s;
    if (!file_100.is_open() || !file_1000.is_open() || !file_10000.is_open()) 
    { 
        cerr << "can't open file" << endl; 
        return 1;
    } 
    
    cout << "compare 100:" << endl;
    DWORD start_time = GetTickCount();
    vec_students = vectorret_read(file_100);
    vec_fails = extract_fails(vec_students);
    DWORD end_time = GetTickCount();
    cout << "vector-100 cost:" << (end_time - start_time) << "ms" << endl;
    start_time = GetTickCount();
    list_students = listret_read(file_100);
    list_fails = extract_fails(list_students);
    end_time = GetTickCount();
    cout << "list-100 cost:" << (end_time - start_time) << "ms" << endl;
    cout << endl;

    vec_students.clear();
    list_students.clear();

    cout << "compare 1000:" << endl;
    start_time = GetTickCount();
    vec_students = vectorret_read(file_1000);
    vec_fails = extract_fails(vec_students);
    end_time = GetTickCount();
    cout << "vector-1000 cost:" << (end_time - start_time) << "ms" << endl;
    start_time = GetTickCount();
    list_students = listret_read(file_1000);
    list_fails = extract_fails(list_students);
    end_time = GetTickCount();
    cout << "list-1000 cost:" << (end_time - start_time) << "ms" << endl;
    cout << endl;

    vec_students.clear();
    list_students.clear();

    cout << "compare 10000:" << endl;
    start_time = GetTickCount();
    vec_students = vectorret_read(file_10000);
    vec_fails = extract_fails(vec_students);
    end_time = GetTickCount();
    cout << "vector-10000 cost:" << (end_time - start_time) << "ms" << endl;
    start_time = GetTickCount();
    list_students = listret_read(file_10000);
    list_fails = extract_fails(list_students);
    end_time = GetTickCount();
    cout << "list-10000 cost:" << (end_time - start_time) << "ms" << endl;
    cout << endl;

    system("pause");
    return 0;
}