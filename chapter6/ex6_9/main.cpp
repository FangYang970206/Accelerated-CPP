#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;    using std::endl;
using std::string;  using std::for_each;
using std::vector;  

string target = "";

void cat(string s){
    target += s;
}

int main(){
    vector<string> vec_s = {"this", "is", "an", "example"};
    for_each(vec_s.begin(), vec_s.end(), cat);
    cout << target << endl;
    system("pause");
    return 0;
}