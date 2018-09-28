#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>

#include "median.h"
#include "grade.h"
#include "student_info.h"
#include "readfile.h"


    
using std::cout;    using std::domain_error;
using std::endl;    using std::string;
using std::max;     using std::vector;
using std::cin;     using std::ifstream;



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
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "optimistic_median", optimistic_median_analysis, did, didnt);

    system("pause");
    return 0;
}