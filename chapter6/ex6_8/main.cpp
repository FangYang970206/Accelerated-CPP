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
    vector<Student_info> did, didnt;
    ifstream file("test.txt");
    read(file, did);
    didnt = classify(did, did_all_hw);
    if(did.empty()){
        cout << "no student did all the homework" << endl;
        return 1;
    }
    if(didnt.empty()){
        cout << "every student did all the homework" << endl;
        return 1;
    }
    int choose[3] = {1, 2, 3};
    write_analysis(cout, "median", analysis, choose[0], did, didnt);
    write_analysis(cout, "average", analysis, choose[1], did, didnt);
    write_analysis(cout, "optimistic_median", analysis, choose[2], did, didnt);

    system("pause");
    return 0;
}