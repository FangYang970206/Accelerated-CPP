#include <iostream>
#include <string>


using std::cin;    using std::endl; 
using std::cout;

int main()
{   
    double first_num, second_num, result;
    cout << "number mutiply between [1,10)"<<endl;
    
    cout << "please enter first number: ";
    cin >> first_num;

    cout << "please enter second number: ";
    cin >> second_num;

    result = first_num*second_num;
    cout << result << endl;
    system("pause");
    return 0;
}
