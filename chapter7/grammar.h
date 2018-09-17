#ifndef __Grammar_H
#define __Grammar_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_Grammar();
std::vector<std::string> gen_sentence(const Grammar&);
std::list<std::string> l_gen_sentence(const Grammar&);
std::vector<std::string> gen_sentence_pro(const Grammar& g);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);
void gen_aux(const Grammar&, const std::string&, std::list<std::string>&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&, std::vector<std::string>&);
int nrand(int);



#endif