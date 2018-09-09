#include <iostream>
#include "cat.h"

using std::cout;    using std::cin;
using std::endl;    using std::vector;
using std::string;  using std::getline;

// demo fail to run , see 17 line in cat.cpp

int main()
{
    string s;
    vector<string> vec, vec2;
    vector<string> vec1{"this is an", "example", "to", "illustrate", "framing"};
    vec2 = vec1;
    vec1 = frame(vec1);
    cout << "Vertical Concatenate: " << endl;
    vec = vcat(vec1, vec2);
    for(vector<string>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }
    cout << endl;
    cout << "Horizontal Concatenate: " << endl;
    vec = hcat(vec2, vec1);
    for(vector<string>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }
    system("pause");
    return 0;
}