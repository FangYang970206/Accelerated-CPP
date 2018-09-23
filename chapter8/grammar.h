#ifndef __Grammar_H
#define __Grammar_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <stdexcept>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_Grammar();
bool bracketed(const std::string&);
int nrand(int);

template <class OutputIterator>
OutputIterator gen_aux(const Grammar& g, const std::string& word, OutputIterator d)
{
    if(!bracketed(word)){
        *d = word;
    }else{
        Grammar::const_iterator it = g.find(word);
        if(it == g.end())
            throw std::logic_error("empty rule");
        const Rule_collection& c = it->second;
        const Rule& r = c[nrand(c.size())];
        for(Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, d);
    }
}

template <class OutputIterator>
OutputIterator gen_sentence(const Grammar& g, OutputIterator d)
{
    gen_aux(g, "<sentence>", d);
}

#endif