#include <iostream>
#include <vector>
#include <algorithm>


using std::cout;    using std::endl;
using std::vector;  using std::copy;
using std::back_inserter;

/* 1. if the vector is emtpy, the v.begin() does not exist. 
   so copy function can't run, we need to push back a value into vector;
   2. the third parameter of copy function should use back_inserter, 
   or just replace the corresponding *iterator.
*/

int main(){
    vector<int> u(10, 100);
    vector<int> v; 
    // copy(u.begin(), u.end(), v.begin()); 
    copy(u.begin(), u.end(), back_inserter(v));
    for(vector<int>::size_type i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}