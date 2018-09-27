#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <class T, class Iterator>
T median(Iterator begin, Iterator end)
{
    if(begin == end)
        throw domain_error("median of an empty container");

    vector<T> vec;
    copy(begin, end, back_inserter(vec));
    sort(vec.begin(), vec.end());
    size_t mid = vec.size() / 2;
    return vec.size() % 2 == 0? (vec[mid] + vec[mid-1])/2 : vec[mid];
}