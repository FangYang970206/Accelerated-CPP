#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


using std::vector; using std::string;
using std::max;    using std::cout;
using std::endl;   


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

int main()
{
    vector<string> vec;
    vec = frame(vec);
    for(vector<string>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }
    system("pause");
    return 0;
}