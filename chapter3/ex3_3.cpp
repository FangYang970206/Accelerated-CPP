#include <iostream>
#include <string>
#include <map>

using std::cout; using std::endl;
using std::map;  using std::string;
using std::cin;

int main()
{
    string x;
    map<string, int> m;
    
    cout << "please enter string, use space as Separator(if exit, use ctrl+z) :" <<endl;
    while( cin >> x)
    {   
        m[x]++;
    }

    for(map<string, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ":" << it->second <<endl;
    }

    system("pause");
    return 0;
}