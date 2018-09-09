#ifndef __READFILE_H_
#define __READFILE_H_


#include <vector>
#include <list>
#include <string>
#include <fstream>
#include "student_info.h"

std::vector<Student_info> vectorret_read(std::ifstream&);
std::list<Student_info> listret_read(std::ifstream&);


#endif