#include <ctype.h>
#include "split.h"

using std::vector; using std::string;
using std::isspace;

vector<string> split(const string& s){
    vector<string> vec;
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
            vec.push_back(s.substr(i, j -i));
            i = j;
        }
    }
    return vec;
}
