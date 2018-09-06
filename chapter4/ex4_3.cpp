#include <iostream>
#include <iomanip>
#include <math.h>


using std::endl;   using std::cout;
using std::setw;   using std::cin;

int compute_pow(int num)
{
    int i = 0;
    while(num > 0)
    {
        num /= 10;
        i++;
    }
    return i;
}

int main()
{   
    int num = 0;
    cout << "please enter the biggest number(int): ";
    cin >> num;
    for(int i = 1; i <= num; i++)
    {
        cout << setw(compute_pow(num)) << i << "  "<< setw(compute_pow(num*num)) << i*i << endl;
    }
    system("pause");
    return 0;
}