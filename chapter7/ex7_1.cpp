#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, int> PAIR;  

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) 
{  
  return lhs.second < rhs.second;
}  

int main(){
    string s;
    map<string, int> counters;

    while(cin >> s)
        ++counters[s];
    
    vector<PAIR> counters_vec(counters.begin(), counters.end());
    sort(counters_vec.begin(), counters_vec.end(), cmp_by_value);
    for(vector<PAIR>::const_iterator it = counters_vec.begin();
        it != counters_vec.end(); it++){
            cout << it->first << "\t" << it->second << endl;
        }
    system("pause");
    return 0;
}