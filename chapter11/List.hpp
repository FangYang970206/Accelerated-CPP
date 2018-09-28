//refer https://github.com/bitsai/book-exercises/blob/master/Accelerated%20C%2B%2B/chapter10/List.hpp
#pragma once

#include <cstdarg>
#include <memory>

template <class T> class list {
    
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;

        list() { resize(0); }
        list(const list& other) { clone(other.beg_iter, other.end_iter); }
        list(const_iterator b, const_iterator e) { clone(b, e); }
        list& operator=(const list&);
        size_t size() {return end_iter-beg_iter;}
        bool empty() {return (end_iter-beg_iter)==0;}
        void push_back(const_reference);
        ~list() { destroy(); }

        const_iterator begin() const { return beg_iter; }
        const_iterator end() const { return end_iter; }

    private:
        iterator beg_iter;
        iterator end_iter;
        std::allocator<value_type> alloc;

        void clone(const_iterator, const_iterator);
        void destroy();
        void resize(size_type);
};


template <class T> list<T>& list<T>::operator=(const list<T>& other) {
  if (this != &other) {
    destroy();
    clone(other.beg_iter, other.end_iter);
  }

  return *this;
}


template <class T> void list<T>::clone(const_iterator b, const_iterator e) {
  resize(e - b);
  uninitialized_copy(b, e, beg_iter);
}


template <class T> void list<T>::destroy() {
  if (beg_iter) {
    for (iterator it = beg_iter; it != end_iter; ++it) alloc.destroy(it);
    alloc.deallocate(beg_iter, end_iter - beg_iter);
  }
  beg_iter = end_iter = 0;
}


template <class T> void list<T>::resize(size_type n) {
  beg_iter = alloc.allocate(n);
  end_iter = beg_iter + n;
}


template <class T> void list<T>::push_back(const T& value){
    alloc.construct(end_iter, value);
    //*end_iter = value;//segmentation fault
    end_iter++;
}


// template <class T> void list<T>::push_back(const T& value){
//     *this = cons(value, *this);
// }

// template <class T> list<T> cons(const T& e, list<T>& l){
//     list<T> new_l;
//     new_l.resize(l.size() + 1);
//     new_l.alloc.construct(new_l.begin(), e);
//     uninitialized_copy(l.begin(), l.end(), new_l.begin() + 1);
//     return new_l;
// }
