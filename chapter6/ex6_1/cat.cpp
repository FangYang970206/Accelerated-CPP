#include <math.h>
#include "cat.h"


using std::vector;   using std::string;
using std::max;

vector<string> hcat(const std::vector<std::string>& left,  const std::vector<std::string>& right)
{
    vector<string> ret;
    typedef vector<string>::const_iterator iter;
    iter i = left.begin(), j = right.begin();
    string::size_type width = maxwidth(left) + 1;
    while(i != left.end() || j != right.end()){
        string s;
        if(i != left.end())
            s = *i++;
        s += string(width - s.size(), ' ');
        if(j != right.end())
            s += *j++;
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
    for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); it++){
        max_len = max(max_len, (*it).size());
    }
    return max_len;
}

vector<string> frame(const vector<string>& vec)
{
    vector<string> ret;
    string::size_type maxlen = maxwidth(vec);
    string border(maxlen+2, '*');
    ret.push_back(border);
    for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); it++){
        string s;
        s = "*" + *it + string(maxlen-(*it).size(), ' ') + "*";
        ret.push_back(s);
    }
    ret.push_back(border);
    return ret;
}