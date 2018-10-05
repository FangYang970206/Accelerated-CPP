#ifndef __CAT_H_
#define __CAT_H_

#include <vector>
#include "Str.hpp"


std::vector<Str> hcat(const std::vector<Str>&,  const std::vector<Str>&);
std::vector<Str> vcat(const std::vector<Str>&,  const std::vector<Str>&);
std::vector<Str> frame(const std::vector<Str>&);
Str::size_type maxwidth(const std::vector<Str> &);




#endif