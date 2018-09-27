#include <iostream>
#include <string>
#include <fstream>

using namespace std;


size_t strlen(const char* p)
{
    size_t size = 0;
    while( *p++ != '\0')
        size++;
    return size;
}

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

char* duplicate_chars(const char* p)
{
    size_t length = strlen(p) + 1;
    char* result = new char[length];
    copy(p, p + length, result);
    return result;
}

int main(int argc, char** argv)
{
    if(argc > 1){
        int i;
        for(i = 1; i < argc-1; ++i)
            cout << argv[i] << " ";
        cout << argv[i] << endl;
    }
    const char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << "strlen(hello): " << strlen(hello) << endl;
    cout << "letter_grade(90): " << letter_grade(90) << endl;
    cout << "letter_grade(64): " << letter_grade(64) << endl;
    cout << "letter_grade(50): " << letter_grade(50) << endl;

    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    string s;

    while(getline(infile, s))
        outfile << s << endl;

    cout << "duplicate_chars(hello): " << duplicate_chars(hello) << endl ;
    system("pause");
    return 0;
}