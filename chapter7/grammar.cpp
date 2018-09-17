//some code from https://github.com/bitsai/book-exercises/blob/master/Accelerated%20C%2B%2B/chapter07/7-6.cpp
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

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

list<string> l_gen_sentence(const Grammar& g)
{
    list<string> ret;
    gen_aux(g, "<sentence>", ret);
   
    return ret;
}

vector<string> gen_sentence_pro(const Grammar& g) {
  vector<string> sentence;
  vector<string> tokens;
  tokens.push_back("<sentence>");

  while (!tokens.empty()) {
    string token = tokens.back();
    tokens.pop_back();
    gen_aux(g, token, sentence, tokens);
  }

  return sentence;
}

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if(!bracketed(word)){
        ret.push_back(word);
    }else{
        Grammar::const_iterator it = g.find(word);
        if(it == g.end())
            throw logic_error("empty rule");
        const Rule_collection& c = it->second;
        const Rule& r = c[nrand(c.size())];
        for(Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

void gen_aux(const Grammar& g, const string& word, list<string>& ret)
{
    if(!bracketed(word)){
        ret.push_back(word);
    }else{
        Grammar::const_iterator it = g.find(word);
        if(it == g.end())
            throw logic_error("empty rule");
        const Rule_collection& c = it->second;
        const Rule& r = c[nrand(c.size())];
        for(Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, ret);
    }
}

void gen_aux(const Grammar& g, const string& token, 
	     vector<string>& sentence, vector<string>& tokens) {
  if (!bracketed(token)) {
    sentence.push_back(token);
  } else {
    // locate the rule that corresponds to `token'
    Grammar::const_iterator it = g.find(token);

    if (it == g.end())
      throw logic_error("empty rule");

    // fetch the set of possible rules
    const Rule_collection& c = it->second;

    // from which we select one at random
    const Rule& r = c[nrand(c.size())];

    // push rule's tokens onto stack of tokens
    // (in reverse order, because we're pushing and popping from the back)
    for (Rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
      tokens.push_back(*i);
  }
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