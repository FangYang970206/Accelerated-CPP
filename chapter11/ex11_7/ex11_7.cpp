#include <algorithm>
#include <iomanip>

#include "student_info.h"
#include "cat.h"

using namespace std;

int main()
{
    Vec<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(record.read(cin)){
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for(Vec<Student_info>::size_type i = 0;
        i != students.size(); ++i){
            cout << setw(maxlen + 1) << students[i].name();
            try{
                double final_grade = students[i].grade();
                streamsize prec = cout.precision();
                cout << setprecision(3) << final_grade
                     << setprecision(prec) << endl;
            }catch(domain_error e){
                cout << e.what() << endl;
            }
        }
    
    string s;
    Vec<string> vec, vec1, vec2;
    vec1.push_back("this is an");
    vec1.push_back("example");
    vec1.push_back("illustrate");
    vec1.push_back("framing");
    vec2 = vec1;
    vec1 = frame(vec1);
    cout << "Vertical Concatenate: " << endl;
    vec = vcat(vec1, vec2);
    for(Vec<string>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }
    cout << endl;
    cout << "Horizontal Concatenate: " << endl;
    vec = hcat(vec2, vec1);
    for(Vec<string>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }    
    system("pause");
    return 0;
}