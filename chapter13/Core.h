#pragma once

#include <iostream>
#include <vector>
#include <string>

class Core
{
    friend class Student_info;
    public:
        Core() : midterm(0), final(0) {
            //std::cout << "Core() : midterm(0), final(0)" << std::endl; //test for 13-1
            }
        Core(std::istream& is) {read(is); 
            //std::cout << "Core(std::istream& is)" << std::endl; //test for 13-1
            };
        std::string name() const;
        virtual std::istream& read(std::istream&);
        virtual double grade() const;
        virtual ~Core() {};
        virtual Core* clone() const {return new Core(*this);}
        virtual bool valid() const {return !homework.empty();}
        virtual std::string letter_grade();

    protected:
        std::istream& read_common(std::istream&);
        std::vector<double> homework;
        double midterm, final;
  
    private:
        std::string n;
};

std::istream& read_hw(std::istream&, std::vector<double>&);
bool compare(const Core&, const Core&);