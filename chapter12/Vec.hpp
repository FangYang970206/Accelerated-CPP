#pragma once

#include <cstddef>
#include <memory>

using namespace std;


template <class T> 
class Vec{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        Vec() {create();}
        template <class In> Vec(In i, In j) {create(i, j);}
        Vec(const Vec& v) {create(v.begin(), v.end());}
        explicit Vec(size_type n, const T& val = T()) {create(n, val);}
        Vec& operator=(const Vec&);

        T& operator[](size_type i) {return data[i];}
        const T& operator[](size_type i) const {return data[i];}

        size_type size() const {return avail - data;}
        bool empty() const {return size()==0;}
        void clear() {uncreate();}

        iterator begin() {return data;}
        const_iterator begin() const {return data;}
        iterator end() {return avail;}
        const_iterator end() const {return avail;}
        template <class In>
        void insert(iterator, In, In);//ex12-12
        template <class In>
        void assign(In, In); //ex12-13
        iterator erase(iterator position){
            for(iterator i = position; i != avail; i++){
                alloc.destroy(i);
                if(i != avail -1)
                    alloc.construct(i, *(i+1));
            }
            -- avail;
            return position;
        }
        void push_back(const T& val){
            if(avail == limit)
                grow();
            unchecked_append(val);
        }
        ~Vec() {uncreate();}
    private:
        iterator data;
        iterator avail;
        iterator limit;

        allocator<T> alloc;

        void create();
        void create(size_type, const T&);

        template <class In> void create(In, In);
        
        void uncreate();

        void grow();
        void unchecked_append(const T&);
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if(&rhs != this){
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T> void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T>
template <class In>
void Vec<T>::create(In i, In j )
{
    data = alloc.allocate(j-i);
    limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate()
{
    if(data){
        iterator it = avail;
        while(it != data)
            alloc.destroy(--it);
            
        alloc.deallocate(data, limit - data);
    }
    data = limit = avail = 0;
}

template <class T> void Vec<T>::grow()
{
    size_type new_size = max(2*(limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_copy(data, avail, new_data);

    uncreate();
    
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}

template <class T>
template <class In>
void Vec<T>::insert(iterator p, In i, In j)
{
    size_type new_size = (avail - data) + (j - i);
    iterator new_data = alloc.allocate(new_size);
    uninitialized_copy(data, p, new_data);
    uninitialized_copy(i, j, new_data + (p - data));
    iterator new_avail = uninitialized_copy(p, avail, new_data + (p - data) + (j -i));

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class In>
void Str::assign(In i, In j)
{
    uncreate();
    create(i, j);
}