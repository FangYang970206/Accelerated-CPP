#include <algorithm>
#include <map>
#include <iostream>
#include "url.h"

using namespace std;

map<string, vector<int> > xref_pro(istream& in)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while(getline(in, line)){
        ++line_number;

        vector<string> words = find_urls(line);
        for(vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it)
            if(find(ret[*it].begin(),ret[*it].end(), line_number) == ret[*it].end())
                ret[*it].push_back(line_number);
    }
    return ret;
}

int main()
{
    map<string, vector<int> > ret = xref_pro(cin);

    for(map<string, vector<int> >::const_iterator it = ret.begin();
        it != ret.end(); it++){
            cout << it->first << " occurs on ";
            string s = it->second.size()==1? "line: " : "lines: ";
            cout << s;
            vector<int>::const_iterator line_it = it->second.begin();
            cout << *line_it;
            ++line_it;
            while(line_it != it->second.end()){
                cout << ", " << *line_it;
                ++line_it;
            }
            cout << endl;
        }
        system("pause");
        return 0;
}