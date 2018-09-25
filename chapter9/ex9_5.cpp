#include <algorithm>
#include <iomanip>
#include "PF_student_info.h"


using namespace std;


int main()
{
    vector<PF_Student_info> students;
    PF_Student_info record;
    string::size_type maxlen = 0;

    while(record.read(cin)){
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for(vector<PF_Student_info>::size_type i = 0;
        i != students.size(); ++i){
            cout << setw(maxlen + 1) << students[i].name();    
            cout << ": " << students[i].grade() << endl;    
        }
    system("pause");
    return 0;
}