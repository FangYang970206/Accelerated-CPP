#include <iostream>
#include "split.h"


using std::cout;      using std::cin;       
using std::vector;    using std::string;
using std::getline;   using std::endl;


int main(){
    string s;
    while(getline(cin, s)){
        vector<string> v = split(s);

        for(vector<string>::size_type i = 0; i != v.size(); i++){
            cout << v[i] << endl;
        }
    }
    
    system("pause");
    return 0;
    
}