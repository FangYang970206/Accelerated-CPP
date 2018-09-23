#include <cstdlib>
#include <fstream>
#include "grammar.h"
#include "split.h"

using namespace std;

Grammar read_Grammar()
{
    Grammar ret;
    string line;
    ifstream file("Grammar.txt");
    while(getline(file, line)){
        vector<string> entry = split(line);
        if(!entry.empty())
            ret[entry[0]].push_back(Rule(entry.begin()+1, entry.end()));
    }
    return ret;
}

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}


int nrand(int n)
{
    if(n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    
    const int bucket_size = RAND_MAX / n;
    int r;
    
    do r = rand() / bucket_size;
    while(r >= n);

    return r;
}