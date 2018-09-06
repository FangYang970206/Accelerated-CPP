#include <iostream>
#include <string>
#include <vector>


using std::string; using std::cout;
using std::cin;    using std::endl;
using std::vector;

double grade(const double midterm, const double final, const vector<double>& homework)
{
    static double result = 0;

    for(vector<double>::size_type i = 0; i != homework.size(); i++)
    {
        result += homework[i];
    }

    result /= homework.size();
    result *= 0.4;
    result += midterm * 0.2 + final * 0.4;

    return result;
}

int main()
{
    vector<string> names;
    vector<double> grades;
    vector<double> homework;
    int n = 3;  // the time of homework is 3
    double a[n];
    string name;
    double midterm=0, final=0;
    cout << "input follow: cin >> name >> midterm >> final >> a[0] >> a[1] >> a[2]" << endl;
    while(cin >> name >> midterm >> final >> a[0] >> a[1] >> a[2])
    {
        names.push_back(name);
        homework.push_back(a[0]);
        homework.push_back(a[1]);
        homework.push_back(a[2]);
        grades.push_back(grade(midterm, final, homework));
    }

    for(vector<string>::size_type i = 0; i != names.size(); i++)
    {
        cout << names[i] << ":" << grades[i] << endl;
    }

    system("pause");
    return 0;
}