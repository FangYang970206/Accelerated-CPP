#include "PF_student_info.h"
#include "PF_grade.h"


using namespace std;


int main()
{
    PF_Student_info s_record;
    PF_grade g_record;

    while(s_record.read(cin))
        g_record.add_student(s_record);
    
    g_record.print_grades();

    system("pause");
    return 0;
}