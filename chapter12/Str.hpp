#pragma once

#include <stdexcept>
#include <cstring>
#include <memory>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cctype>

using std::isspace;
using std::vector;
using std::out_of_range;
using std::strlen;
using std::uninitialized_copy;
using std::uninitialized_fill;
using std::strcmp;
using std::istream;
using std::ostream;
using std::ostream_iterator;
using std::allocator;

class Str{
    public:
        typedef size_t size_type;
        typedef char* iterator;
        typedef const char* const_iterator;

        Str() {create(0, '\0');}
        Str(size_type n, char c) {create(n, c);}
        Str(const char* cp) {create(cp, cp + strlen(cp));}
        Str(const Str& s) {create(s.begin(), s.end());}
        template <class In> Str(In b, In e) {create(b, e);}
        Str& operator = (const Str&);
        ~Str() {uncreate();}
        //ex12-7
        iterator begin() {return chars;}
        const_iterator begin() const {return chars;}
        iterator end() {return chars+length-1;}
        const_iterator end() const {return chars+length-1;}
        
        size_type size() const {return length-1;}
        //ex12-2
        const char* c_str() const {return chars;}
        const char* data() const {return chars;}
        size_type copy(iterator, size_type, size_type = 0) const;
        
        operator char*() {return chars;}
        operator const char*() const {return chars;}
        char& operator [] (size_type i) {return chars[i];} 
        const char& operator [] (size_type i)const {return chars[i];}
        Str& operator += (const Str&);
        //ex12-6
        operator bool() const {return (size()>0);}
        //ex12-12
        template <class In>
        void insert(iterator, In, In);
        
    private:
        iterator chars;
        size_type length;
        allocator<char> alloc;

        void create(size_type, char);
        template <class In> void create(In, In);
        void uncreate();
};


istream& operator>>(istream&, Str&);
ostream& operator<<(ostream&, const Str&);
Str operator + (const Str&, const Str&);
Str operator + (const Str&, const char*);
Str operator + (const char*, const Str&);
//ex12-3
inline bool operator < (const Str& lhs, const Str& rhs);
inline bool operator > (const Str& lhs, const Str& rhs);
inline bool operator >= (const Str& lhs, const Str& rhs);
inline bool operator <= (const Str& lhs, const Str& rhs);
//ex12-4
inline bool operator == (const Str& lhs, const Str& rhs);
inline bool operator != (const Str& lhs, const Str& rhs);
//ex12-5
Str convert(const char*);
const char* convert(const Str&);
//ex12-8
istream& getline(istream&, Str&);
//ex12-9
ostream_iterator<char>& operator<<(ostream_iterator<char>&, Str&);

template <class In> void Str::create(In b, In e)
{
    length = e - b + 1;
    chars = alloc.allocate(length);
    uninitialized_copy(b, e, chars);
    alloc.construct(chars+length-1, '\0');
} 

template <class In>
void Str::insert(iterator p, In i, In j)
{
    size_type new_length = length + (j - i);
    iterator new_chars = alloc.allocate(new_length);
    uninitialized_copy(chars, p, new_chars);
    uninitialized_copy(i, j, new_chars + (p - chars));
    uninitialized_copy(p, chars + length - 1, new_chars + (p - chars) + (j -i));
    alloc.construct(new_chars + new_length - 1, '\0');

    uncreate();

    length = new_length;
    chars = new_chars;
}

inline bool operator < (const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

inline bool operator > (const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

inline bool operator == (const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

inline bool operator != (const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

inline bool operator >= (const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

inline bool operator <= (const Str& lhs, const Str& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}


