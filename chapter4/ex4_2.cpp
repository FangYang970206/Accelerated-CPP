#include <iostream>
#include <iomanip>

using std::endl;   using std::cout;
using std::setw;

int main()
{
    for(int i = 0; i <= 100; i++)
    {
        cout << setw(3) << i << "  "<< setw(5) << i*i << endl;
    }
    system("pause");
    return 0;
}