#include "Str.hpp"


void Str::create(size_type n, char c)
{
    length = n + 1;
    chars = alloc.allocate(length);
    uninitialized_fill(chars, chars+length-1, c);
    alloc.construct(chars+length-1, '\0');
}

void Str::uncreate()
{
    if(chars){
        iterator it = chars + length;
        while(it != chars) alloc.destroy(--it);
        alloc.deallocate(chars, length);
    }
    length = 0;
    chars = 0;
}

Str& Str::operator = (const Str& s)
{
    if(&s != this){
        uncreate();
        create(s.begin(), s.end());
    }
    return *this;
}

Str& Str::operator += (const Str& s){
    size_type new_length = length + s.size();
    iterator new_chars = alloc.allocate(new_length);
    uninitialized_copy(chars, chars + length - 1, new_chars);
    uninitialized_copy(s.begin(), s.end(), new_chars + length - 1);
    alloc.construct(new_chars + new_length - 1);
    
    chars = new_chars;
    length = new_length;
}

Str::size_type Str::copy(iterator p, size_type n, size_type pos) const
{
    if(pos > size())
        throw out_of_range("pos > size()");
    size_type copy_length = std::min(n, size()-pos);
    std::copy(chars+pos, chars+pos+copy_length, p);
    return copy_length;
}

Str operator + (const Str& s1, const Str& s2)
{
    Str s = s1;
    s += s2;
    return s;
}

Str operator + (const Str& s1, const char* chs)
{
    Str s = s1;
    s += Str(chs, chs + strlen(chs));
    return s;
}

Str operator + (const char* chs, const Str& s1)
{
    Str s(chs, chs+strlen(chs));
    s += s1;
    return s;
}

Str convert(const char* chs)
{
    Str s(chs);
    return s;
}

const char* convert(const Str& s)
{
    const char* chs = s.c_str();
    return chs;
}

int is_newline(int c)
{ 
    return c=='\n';
}

istream& read_until(istream& is, Str& s, int is_stop_char(int))
{
    vector<char> vec;
    char c;
    while(is.get(c) && isspace(c));

    if(is){
        do vec.push_back(c);
        while(is.get(c) && !is_stop_char(c));
        if(is) is.unget();
    }

    s = Str(vec.begin(), vec.end());
    return is;
}

istream& operator>>(istream& is, Str& s)
{
    return read_until(is, s, isspace);
}

istream& getline(istream& is, Str& s)
{
    return read_until(is, s, is_newline);
}

ostream& operator<<(ostream& os, const Str& s)
{
    for(size_t i = 0; i != s.size(); i++)
        os << s[i];
    return os;
}

ostream_iterator<char>& operator<<(ostream_iterator<char>& osi, Str& s)
{
    std::copy(s.begin(), s.end(), osi);
    return osi;
}