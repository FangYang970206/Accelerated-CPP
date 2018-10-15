#include "Core.h"
#include "grade.h"

using namespace std;

string Core::name() const 
{
    //cout << "Core::name()" << endl; //test for 13-2
    return n;
}

double Core::grade() const 
{
    //cout << "Core::grade()" << endl; //test for 13-2
    return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
    in >> n >> midterm >> final;
    return in;
}

istream& Core::read(istream& in)
{
    read_common(in);
    read_hw(in, homework);
    return in;
}

string Core::letter_grade()
{
    double grade = Core::grade();
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

istream& read_hw(istream& in, vector<double>& hw)
{
    if(in)
    {
        hw.clear();
        double x;
        while(in >> x)
            hw.push_back(x);
        
        in.clear();
    }
    return in;
}

bool compare(const Core& c1, const Core& c2)
{
    return c1.name() < c2.name();
}