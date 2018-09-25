#include <iostream>

#include "Student_info.h"

using namespace std;

int main() 
{
    Student_info record;
    if (record.valid()) record.grade();
    system("pause");
    return 0;
}