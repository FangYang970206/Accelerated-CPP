#pragma once


#include <memory>


template <class T> 
class Vec{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;
        Vec() {create();}
        Vec(const Vec& v) {create(v.begin(), v.end());}
        explicit Vec(size_type n, const T& val = T()) {create(n, val);}
        T& operator[](size_type i) {return data[i];}
        const T& operator[](size_type i) const {return data[i];}
        Vec& operator=(const Vec&);
        size_type size() const {return limit - data;}
        bool empty() const {return size()==0;}
        iterator begin() {return data;}
        const_iterator begin() const {return data;}
        iterator end() {return limit;}
        const_iterator end() const {return limit;}
        void clear() {uncreate();}
        void insert(iterator this_end, iterator other_begin, iterator other_end);
        iterator erase(iterator position){
            for(iterator i = position; i != avail; i++){
                alloc.destory(i);
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
        void create(const_iterator, const_iterator);
        
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
    uninitalized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j )
{
    data = alloc.allocate(j-i);
    limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate()
{
    if(data){
        iterator it = avail;
        while(it != data)
            alloc.destory(--it);
        
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

template <class T> void Vec<T>::insert(iterator this_end, 
                                       iterator other_begin, 
                                       iterator other_end)
{   
    if(other_end - other_begin < 0)
        return 1;
    while(other_begin != other_end)
        *this.push_back(*other_begin++);
}