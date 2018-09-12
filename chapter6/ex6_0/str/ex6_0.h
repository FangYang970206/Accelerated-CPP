#ifndef __EX6_0_H
#define __EX6_0_H

#include <vector>
#include <string>


std::vector<std::string> vcat(std::vector<std::string>& , std::vector<std::string> &);
std::vector<std::string> split(const std::string & );
std::vector<std::string> find_urls(const std::string & );
std::string::size_type maxwidth(const std::vector<std::string> & );
std::vector<std::string> frame(const std::vector<std::string>&);
std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);
std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);
bool is_palindrome(const std::string &);
bool not_url_char(char);
bool not_space(char);
bool space(char);



#endif