#ifndef __SPLIT_H_
#define __SPLIT_H_


#include <vector>
#include <string>
#include <cctype>

template <class Out>
void split(const std::string & s, Out os)
{
    typedef std::string::size_type string_size;
    string_size i = 0;
    while(i != s.size()){
        while( i != s.size() && std::isspace(s[i])){
            ++i;
        }

        string_size j = i;
        while(j != s.size() && !std::isspace(s[j])){
            ++j;
        }
        if(i != j){
            *os++ = s.substr(i, j -i);
            i = j;
        }
    }
}

std::vector<std::string> split(const std::string & );


#endif