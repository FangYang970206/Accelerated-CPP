#include <math.h>
#include "cat.h"


using std::string;
using std::max;

Vec<string> hcat(const Vec<std::string>& left,  const Vec<std::string>& right)
{
    Vec<string> ret;
    string::size_type i =0, j =0;
    string::size_type width = maxwidth(left) + 1;
    while(i != left.size() || j != right.size()){
        string s;
        if(i != left.size())
            s = left[i++];
        s += string(width - s.size(), ' ');
        if(j != right.size())
            s += right[j++];
        ret.push_back(s);
    }
    return ret;
} 

Vec<string> vcat(const Vec<std::string>& top,  const Vec<std::string>& bottom)
{
    Vec<string> ret = top;
    // typedef Vec<string>::const_iterator iter;
    // iter this_begin = ret.end();
    // iter other_begin = bottom.begin();
    // iter other_end = bottom.end();
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;    
}

string::size_type maxwidth(const Vec<string> & vec)
{
    string::size_type max_len = 0;
    for(Vec<string>::size_type i = 0; i != vec.size(); i++){
        max_len = max(max_len, vec[i].size());
    }
    return max_len;
}

Vec<string> frame(const Vec<string>& vec)
{
    Vec<string> ret;
    string::size_type maxlen = maxwidth(vec);
    string border(maxlen+2, '*');
    ret.push_back(border);
    for(Vec<string>::size_type i = 0; i != vec.size(); i++){
        string s;
        s = "*" + vec[i] + string(maxlen-vec[i].size(), ' ') + "*";
        ret.push_back(s);
    }
    ret.push_back(border);
    return ret;
}