#include <math.h>
#include "center.h"


using std::vector;   using std::string;
using std::max;

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

vector<string> center(const vector<string>& vec_s){
    vector<string> ret;
    string s;
    string::size_type max_len = maxwidth(vec_s);
    for(vector<string>::const_iterator it = vec_s.begin(); it != vec_s.end(); it++){
        string::size_type minus_res = max_len - (*it).size();
        s = string(minus_res/2, ' ') + (*it) + string(minus_res-(minus_res/2), ' ');
        ret.push_back(s);
    }
    return ret;
}