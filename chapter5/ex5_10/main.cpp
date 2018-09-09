#include <iostream>
#include "str.h"


using std::cout;    using std::getline;
using std::endl;    using std::string;
using std::list;    using std::cin;


int main()
{
    string s;
    list<string> l, ret; 
    getline(cin, s);
    l = split(s);
    ret = palindrome(l);
    if(ret.size() == 0){
        cout << "no palindrome" << endl;
    }else{
        cout << "palindrome: " << endl;
        for(list<string>::const_iterator it = ret.begin(); it != ret.end(); it++){
            cout << *it << endl;
        }
    }
    system("pause");
    return 0;
}