#include <iostream>
#include "center.h"

using std::cout;    using std::cin;
using std::endl;    using std::vector;
using std::string;  using std::getline;


int main()
{
    string s;
    vector<string> vec{"an", "example", "to", "illustrate", "framing"};
    vec = center(vec);
    vec = frame(vec);
    for(vector<string>::size_type i = 0; i != vec.size(); i++){
        cout << vec[i] << endl;
    }
    system("pause");
    return 0;
}