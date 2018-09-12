#include <iostream>
#include <vector>
#include <algorithm>


using std::cout;    using std::endl;
using std::vector;  using std::copy;
using std::back_inserter;

int main(){
    vector<int> u(10, 100);
    vector<int> v; 
    //method 1 (when v is empty, it's easy and fast)
    v = u;
    v.clear();
    //method 2 (generality)
    for(vector<int>::const_iterator it = u.begin(); it != u.end(); it++)
        v.push_back(*it);
    v.clear();
    //method 3 (more easier and faster than method 2)
    copy(u.begin(), u.end(), back_inserter(v));

    system("pause");
    return 0;
}