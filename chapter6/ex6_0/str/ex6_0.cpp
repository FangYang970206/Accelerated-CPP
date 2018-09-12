#include <algorithm>
#include "ex6_0.h"


using std::vector;      using std::string;
using std::copy;        using std::back_inserter;
using std::isspace;     using std::find_if;
using std::equal;       using std::isalnum;
using std::search;      using std::isalpha;
using std::max;


vector<string> vcat(vector<string>& top, vector<string> & bottom){
    vector<string> ret = top;
    copy(bottom.begin(), bottom.end(), back_inserter(ret));
    return ret;
}

bool space(char c){
    return isspace(c);
}

bool not_space(char c){
    return !isspace(c);
}

bool not_url_char(char c){
    static const string url_ch = "~;/?:@=&$-_.+!*(),'";
    return ! (isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

bool is_palindrome(const string & s){
    return equal(s.begin(), s.end(), s.rbegin());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){
    static const string sep = "://";
    typedef string::const_iterator iter;
    iter i = b;
    while((i = search(i, e, sep.begin(), sep.end())) != e){
        if( i != b && i + sep.size() != e){
            iter beg = i;
            while(beg != b && isalpha(beg[-1])){
                beg--;
                if(beg != i && i + sep.size() != e && !not_url_char(i[sep.size()])){
                    return beg;
                }
            }
        }
        if(i != e)
            i += sep.size();
    }
    return e;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e){
    return find_if(b, e, not_url_char);
}

vector<string> split(const string & s){
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while(i != s.end()){
        i = find_if(i, s.end(), not_space);
        iter j = find_if(i, s.end(), space);
        if(i != s.end()){
            ret.push_back(string(i,j));
        }
        i = j;
    }
    return ret;
}

vector<string> find_urls(const string & s){
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    while(b != e){
        b = url_beg(b, e);
        if(b != e){
            iter after = url_end(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }
    return ret;

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

string::size_type maxwidth(const vector<string> & vec)
{
    string::size_type max_len = 0;
    for(vector<string>::size_type i = 0; i != vec.size(); i++){
        max_len = max(max_len, vec[i].size());
    }
    return max_len;
}
