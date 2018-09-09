#ifndef __STR_H_
#define __STR_H_


#include <list>
#include <string>


std::list<std::string> split(const std::string & );
std::list<std::string> word_classify(std::list<std::string> & );
std::list<std::string> palindrome(std::list<std::string> &);
std::list<std::string> find_str(std::list<std::string> &);
std::string maxWidthString(const std::list<std::string> &);
bool judgeUpDownLetter(const std::string &);




#endif