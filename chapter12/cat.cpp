#include <math.h>
#include "cat.h"


using std::vector;
using std::max;

vector<Str> hcat(const std::vector<Str>& left,  const std::vector<Str>& right)
{
    vector<Str> ret;
    Str::size_type i =0, j =0;
    Str::size_type width = maxwidth(left) + 1;
    while(i != left.size() || j != right.size()){
        Str s;
        if(i != left.size())
            s = left[i++];
        s += Str(width - s.size(), ' ');
        if(j != right.size())
            s += right[j++];
        ret.push_back(s);
    }
    return ret;
} 

vector<Str> vcat(const std::vector<Str>& top,  const std::vector<Str>& bottom)
{
    vector<Str> ret = top;
    ret.insert(ret.end(), bottom.begin(), bottom.end());
    return ret;    
}

Str::size_type maxwidth(const vector<Str> & vec)
{
    Str::size_type max_len = 0;
    for(vector<Str>::size_type i = 0; i != vec.size(); i++){
        max_len = max(max_len, vec[i].size());
    }
    return max_len;
}

vector<Str> frame(const vector<Str>& vec)
{
    vector<Str> ret;
    Str::size_type maxlen = maxwidth(vec);
    Str border(maxlen+2, '*');
    ret.push_back(border);
    for(vector<Str>::size_type i = 0; i != vec.size(); i++){
        Str s;
        s = "*" + vec[i] + Str(maxlen-vec[i].size(), ' ') + "*";
        ret.push_back(s);
    }
    ret.push_back(border);
    return ret;
}