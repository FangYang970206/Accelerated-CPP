#include <iostream>

#include "split.h"

using namespace std;

int main()
{
    string s = "fang yang is cool and warm-hearted";
    list<string> result = split(s);
    for(list<string>::const_iterator it = result.begin(); 
            it != result.end(); it++){
              cout << *it << endl;  
    }
    system("pause");
    return 0;
}