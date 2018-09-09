#include <algorithm>
#include <ctype.h>
#include "str.h"


using std::list;    using std::string;
using std::isspace; using std::isupper;
using std::reverse;


list<string> split(const string& s){
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
            list.push_back(s.substr(i, j -i));
            i = j;
        }
    }
    return list;
}

// return upper letter list
list<string> word_classify(list<string> & l ){
    list<string> ret;
    list<string>::iterator it = l.begin();
    bool flag = false;
    while(it != l.end()){
        for(string::size_type i = 0; i != l.size(); i++){
            if(isupper((*it)[i])){
                ret.push_back(*it);
                it = l.erase(it);
                flag = true;
                break;
            }else{
                flag = false;
            }
        }
        if(!flag){
            it++;
        }
    }
    return ret;
}

// string str_reverse(const string & s){
//     string::size_type size = s.size();
//     string ret;
//     for(string::size_type i = size-1; i >= 0; i--){
//         ret += s[i];
//     }
//     return ret;
// }

list<string> palindrome(list<string> & l){
    list<string> ret;
    for(list<string>::iterator it = l.begin(); it != l.end(); it++){
        string s = *it;
        reverse((*it).begin(),(*it).end());
        if(s == *it){
            ret.push_back(*it);
        }
    }
    return ret;
}