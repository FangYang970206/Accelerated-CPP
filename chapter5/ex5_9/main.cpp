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
    ret = word_classify(l);
    cout << "lowcase words: ";
    for(list<string>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << (*it) << " ";
    }
    cout << endl;
    cout << "uppercase words: ";
    for(list<string>::const_iterator it = ret.begin(); it != ret.end(); it++){
        cout << (*it) << " ";
    }
    system("pause");
    return 0;
}