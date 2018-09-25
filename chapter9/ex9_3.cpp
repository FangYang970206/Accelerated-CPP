#include <iostream>
#include <stdexcept>

#include "./student_info.h"

using namespace std;

int main()
{
    try{
        Student_info record;
        record.grade();
    }catch(domain_error e){
        cout << e.what() << endl;
    };
    system("pause");
    return 0;
}