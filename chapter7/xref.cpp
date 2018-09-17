#include <algorithm>
#include "xref.h"
#include "split.h"
#include "url.h"

using namespace std;

map<string, vector<int> > xref(istream& in, vector<string> find_word(const string&))
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while(getline(in, line)){
        ++line_number;

        vector<string> words = find_word(line);
        for(vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it)
            ret[*it].push_back(line_number);
    }
    return ret;
}

map<string, vector<int> > xref_pro(istream& in, vector<string> find_word(const string&))
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while(getline(in, line)){
        ++line_number;

        vector<string> words = find_word(line);
        for(vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it)
            if(find(ret[*it].begin(),ret[*it].end(), line_number) == ret[*it].end())
                ret[*it].push_back(line_number);
    }
    return ret;
}