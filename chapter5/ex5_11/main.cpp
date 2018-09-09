#include <iostream>
#include "str.h"


using std::cout;    using std::getline;
using std::endl;    using std::string;
using std::list;    using std::cin;


int main()
{
    string s, mws;
    list<string> l, ret; 
    getline(cin, s);
    l = split(s);
    ret = find_str(l);
    mws = maxWidthString(ret);
    cout << "The max width string which not contain Uplink letters or Downlink letters: ";
    cout << mws << endl;
    system("pause");
    return 0;
}