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


// typedef list<Student_info> Student_infos;
typedef vector<Student_info> Student_infos;

int main()
{
    Student_infos students, fails;
    ifstream file_1000("1000.txt");
    Student_info record;
    LARGE_INTEGER cpuFreq;
    LARGE_INTEGER startTime;
    LARGE_INTEGER endTime;
    double rumTime=0.0;
    string s;
    if (!file_1000.is_open()) 
    { 
        cerr << "can't open file" << endl; 
        return 1;
    } 

    read(file_1000, students);
    fails = extract_fails(students);
    cout << "success" << endl;
    system("pause");
    return 0;
}