#include <algorithm>
#include "Grad.h"


using namespace std;

istream& Grad::read(istream& in)
{
    read_common(in);
    in >> thesis;
    read_hw(in, Core::homework);
    return in;
}

double Grad::grade() const 
{
    //cout << "Grad::grade()" << endl; //test for 13-2
    return min(Core::grade(), thesis);
}

string Grad::letter_grade()
{
    double grade = Grad::grade();
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

    return "\?\?\?";
}