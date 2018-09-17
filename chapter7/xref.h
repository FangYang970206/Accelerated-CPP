#ifndef __XREF_H_
#define __XREF_H_


#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "url.h"
#include "split.h"


//Be careful of the different find_words functions
std::map<std::string, std::vector<int> > xref(std::istream& in, 
                                              std::vector<std::string> find_word(const std::string&)=split);
std::map<std::string, std::vector<int> > xref_pro(std::istream& in, 
                                                  std::vector<std::string> find_word(const std::string&)=split);



#endif