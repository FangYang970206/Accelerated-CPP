#include <algorithm>
#include <ctype.h>
#include "str.h"


using std::list;    using std::string;
using std::isspace; using std::isupper;
using std::reverse; using std::max;


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

bool judgeUpDownLetter(const string & s){
    char UplinkLetters[] = {'b','d','f','h','k','l','t'};
    char DownlinkLetters[] = {'g','j','p','q','y'};
    for(int i = 0; i != 7; i++){
        //find function return the position.
        if(s.find(UplinkLetters[i]) >= 0 && s.find(UplinkLetters[i]) < s.size()){
            return true;
        }
    }
    for(int i = 0; i != 5; i++){
        if(s.find(DownlinkLetters[i]) >= 0 && s.find(DownlinkLetters[i]) < s.size()){
            return true;
        }
    }
    return false;
}

list<string> find_str(list<string> & l){
    list<string> ret;
    for(list<string>::const_iterator it = l.begin(); it != l.end(); it++){
        if(! judgeUpDownLetter(*it)){
            ret.push_back(*it);
        }
    }
    return ret;
}

string maxWidthString(const list<string> & l)
{
    string maxWidthString;
    string::size_type max_len = 0;
    for(list<string>::const_iterator it = l.begin(); it != l.end(); it++){
        if((*it).size() > max_len){
            max_len = (*it).size();
            maxWidthString = *it;
        }
    }
    return maxWidthString;
}