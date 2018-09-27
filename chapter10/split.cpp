#include <ctype.h>
#include "split.h"

using std::string;
using std::isspace;

list<string> split(const string & s){
    list<string> list;
    typedef string::size_type string_size;
    string_size i = 0;
    while(i != s.size()){
        while( i != s.size() && isspace(s[i])){
            ++i;
        }

        string_size j = i;
        while(j != s.size() && !isspace(s[j])){
            ++j;
        }
        if(i != j){
            string temp = s.substr(i, j -i);
            list.push_back(temp);
            i = j;
        }
    }
    return list;
}
