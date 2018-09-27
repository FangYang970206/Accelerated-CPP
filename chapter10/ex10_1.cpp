#include <algorithm>
#include <iomanip>


#include "student_info.h"


using namespace std;

string letter_grade(double grade)
{
    static const double numbers[] = {
        97, 94, 90, 87, 85, 80, 77, 74, 70, 60, 0
    };

    static const char* const letters[] = {
        "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
    };

    static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

    for(size_t i = 0; i < ngrades; i++){
        if(grade >= numbers[i])
            return letters[i];
    }

    return "?\?\?";
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(record.read(cin)){
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);
    cout << "input data, follow name >> midterm >> final >> vector<double> homework" << endl;
    cout << "double ctrl+z, exit" << endl;
    for(vector<Student_info>::size_type i = 0;
        i != students.size(); ++i){
            cout << setw(maxlen + 1) << students[i].name() << ": ";
            try{
                double final_grade = students[i].grade();
                cout << letter_grade(final_grade) << endl;
            }catch(domain_error e){
                cout << e.what() << endl;
            }
        }
    system("pause");
    return 0;
}