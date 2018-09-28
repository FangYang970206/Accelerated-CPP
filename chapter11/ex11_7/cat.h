#ifndef __CAT_H_
#define __CAT_H_


#include <string>
#include "Vec.hpp"


Vec<std::string> hcat(const Vec<std::string>&,  const Vec<std::string>&);
Vec<std::string> vcat(const Vec<std::string>&,  const Vec<std::string>&);
Vec<std::string> frame(const Vec<std::string>&);
std::string::size_type maxwidth(const Vec<std::string> &);




#endif