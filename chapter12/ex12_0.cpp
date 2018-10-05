#include "Str.h"


using namespace std;


int main()
{
    Str s("hello");
    Str t = "hello";
    s = "hello";
    cout << "s: " << s << endl;
    cout << "t: " << t << endl;

    Str name = "fangyang";
    const Str greeting = "hello" + name + "!";
    cout << greeting << endl;

    system("pause");
    return 0;
}