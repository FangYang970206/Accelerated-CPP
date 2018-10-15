#pragma once

#include "Core.h"



class Grad: public Core{
    public:
        Grad() : thesis(0) {
            //std::cout <<"Grad() : thesis(0)" << std::endl; //test for 13-1
            }
        Grad(std::istream& is) {read(is);
            //std::cout <<"Grad(std::istream& is)" << std::endl; //test for 13-1
            }
        double grade() const;
        std::istream & read(std::istream&);
        Grad* clone() const {return new Grad(*this);}
        std::string letter_grade();

    private:
        double thesis;
};