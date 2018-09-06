#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::cin;  using std::string;

int main()
{
    string x;
    int max_len=0, min_len=0;
    
    while(cin >> x)
    {
        max_len = x.size() > max_len ? x.size() : max_len;
        min_len = x.size() > min_len ? min_len : x.size();
    }

    cout << "The max length of string:" << max_len << endl;
    cout << "The min length of string:" << min_len << endl;

    system("pause");
    return 0;
}