#include <iostream>
#include <algorithm>
#include "cat.h"

using std::cout;    using std::cin;
using std::endl;    using std::vector;
using std::find_if;

bool not_space(char c)
{
    return !isspace(c);
}

bool space(char c)
{
    return isspace(c);
}

vector<Str> split(const Str & s)
{
    typedef Str::const_iterator iter;
    vector<Str> ret;
    iter i = s.begin();
    while(i != s.end()){
        i = find_if(i, s.end(), not_space);
        iter j = find_if(i, s.end(), space);
        if(i != s.end()){
            ret.push_back(Str(i,j));
        }
        i = j;
    }
    return ret;
}

int main()
{
    Str s;
    vector<Str> vec, vec2;
    vector<Str> vec1{"this is an", "example", "to", "illustrate", "framing"};
    vec2 = vec1;
    vec1 = frame(vec1);
    cout << "Vertical Concatenate: " << endl;
    vec = vcat(vec1, vec2);
    for(vector<Str>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }
    cout << endl;
    cout << "Horizontal Concatenate: " << endl;
    vec = hcat(vec2, vec1);
    for(vector<Str>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }

    Str test_split = "I am wonderful man...";
    cout << "test_split: " << test_split << endl;
    vector<Str> ret = split(test_split);
    for (auto& i : ret)
        cout << i << endl;
    system("pause");
    return 0;
}