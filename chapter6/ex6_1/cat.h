#ifndef __CAT_H_
#define __CAT_H_

#include <vector>
#include <string>


std::vector<std::string> hcat(const std::vector<std::string>&,  const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&,  const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::string::size_type maxwidth(const std::vector<std::string> &);




#endif