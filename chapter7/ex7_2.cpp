#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "grade.h"
#include "student_info.h"
#include "readfile.h"

using namespace std;

string student_grade_rank(double grade)
{
    int a = floor(grade/10);
    switch(a){
        case 9:
            return "A";
        case 8:
            return "B";
        case 7:
            return "C";
        case 6:
            return "D";
        default:
            return "F";
    }
}


int main()
{
    ifstream file("1000.txt");
    vector<Student_info> students;
    map<string, int> counters;
    read(file, students);
    for(vector<Student_info>::size_type i = 0; i != students.size(); i++){
        double final_grade = grade(students[i]);
        string grade_rank = student_grade_rank(final_grade);
        counters[grade_rank]++;
    }
    for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++){
        cout << it->first << "\t" << it->second << endl;
    }

    system("pause");
    return 0;
}