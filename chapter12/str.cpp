#include "Str.h"


std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for(Str::size_type i = 0; i != s.size(); ++i)
        os<<s[i];
    return os;
}

std::istream& operator>>(std::istream& is, Str& S)
{
    S.data.clear();
    char c;
    while(is.get(c) && isspace(c));

    if(is){
        do S.data.push_back(c);
        while(is.get(c) && !isspace(c));
        if(is)
            is.unget();
    }
    return is;
}

Str operator + (const Str& s, const Str& t)
{
    Str r = s;
    r += t;
    return r;
}