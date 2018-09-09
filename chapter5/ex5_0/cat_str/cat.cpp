#include <math.h>
#include "cat.h"


using std::vector;   using std::string;
using std::max;

vector<string> hcat(const std::vector<std::string>& left,  const std::vector<std::string>& right)
{
    vector<string> ret;
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

vector<string> vcat(const std::vector<std::string>& top,  const std::vector<std::string>& bottom)
{
    vector<string> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;    
}

string::size_type maxwidth(const vector<string> & vec)
{
    string::size_type max_len = 0;
    for(vector<string>::size_type i = 0; i != vec.size(); i++){
        max_len = max(max_len, vec[i].size());
    }
    return max_len;
}

vector<string> frame(const vector<string>& vec)
{
    vector<string> ret;
    string::size_type maxlen = maxwidth(vec);
    string border(maxlen+2, '*');
    ret.push_back(border);
    for(vector<string>::size_type i = 0; i != vec.size(); i++){
        string s;
        s = "*" + vec[i] + string(maxlen-vec[i].size(), ' ') + "*";
        ret.push_back(s);
    }
    ret.push_back(border);
    return ret;
}