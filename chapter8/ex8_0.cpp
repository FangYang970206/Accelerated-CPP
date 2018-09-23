#include <iostream>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


template <class T>
T median(vector<T> v)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    if(size == 0)
        throw domain_error("median of an empty vector");
    sort(v.begin(), v.end());
    vec_sz mid = size/2;
    return size%2==0? (v[mid]+v[mid-1])/2 : v[mid];
}

template <class T>
T tem_max(const T& left, const T& right)
{
    return left > right? left : right;
}

template <class In, class X>
In tem_find(In b, In e, const X& x)
{
    while(b != e && *b != x)
        ++b;
    return b;
}

template <class In, class Out>
Out tem_copy(In b, In e, Out dest)
{
    while(b != e)
        *dest++ = *b++;
    return dest; 
}

template <class For, class X>
void tem_replace(For beg, For end, const X& x, const X& y)
{
    while(beg != end){
        if(*beg == x)
            *beg = y;
        ++beg;
    }
}

template <class Bi>
void tem_reverse(Bi begin, Bi end)
{
    while(begin != end){
        --end;
        if(begin != end)
            swap(*begin++, *end);
    }
}

template <class Ran, class X>
bool tem_binary_search(Ran begin, Ran end, const X& x)
{
    while(begin < end){
        Ran mid = begin + (end - begin) / 2;
        if(x < *mid)
            end = mid;
        else if(*mid < x)
            begin = mid + 1;
        else return true;
    }
    return false;
}

bool not_space(char c)
{
    return !isspace(c);
}

bool space(char c)
{
    return isspace(c);
}

template <class Out>
void split(const string& s, Out os)
{
    typedef string::const_iterator iter;
    iter i = s.begin();
    while(i != s.end()){
        i = find_if(i, s.end(), not_space);
        iter j = find_if(i, s.end(), space);
        if(i != s.end())
            *os++ = string(i, j);
        
        i = j;
    }
}



int main()
{   
    cout << "test template median: " << endl;
    vector<double> vd = {2,3,5,52,5};
    vector<int> vi = {2,3,4,2,53,52,23,33};
    cout << "vector double: ";
    for(vector<double>::size_type i = 0; i != vd.size(); i ++){
        cout << vd[i] << " ";
    }
    cout << endl;
    cout << "double median: " << median(vd) << endl;
    cout << "vector double: ";
    for(vector<int>::size_type i = 0; i != vi.size(); i ++){
        cout << vi[i] << " ";
    }
    cout << endl;
    cout << "int median: " << median(vi) << endl << endl;
    cout << "test template max: " << endl;
    double left_1 = 1.2, right_1 = 1.5;
    int left_2 = 1, right_2 = 5;
    cout << "double left: " << left_1 <<"  " << "double right: " << right_1 << endl;
    cout << "double max: " << tem_max(left_1, right_1) << endl;
    cout << "int left: " << left_1 <<"  " << "int right: " << right_1 << endl;
    cout << "int max: " << tem_max(left_2, right_2) << endl << endl;
    cout << "test template find: " << endl;
    vector<double> vd_1 = {5, 4, 3, 10, 8, 12};
    vector<int> vi_1 = {5, 4, 3, 10, 8, 12};
    cout << "vector double: ";
    for(vector<double>::size_type i = 0; i != vd_1.size(); i ++){
        cout << vd_1[i] << " ";
    }
    cout << endl;
    cout << "find double: " << *(tem_find(vd_1.begin(), vd_1.end(), 4.0)) << endl;
    cout << "int double: ";
    for(vector<int>::size_type i = 0; i != vi_1.size(); i ++){
        cout << vi_1[i] << " ";
    }
    cout << "find int: " << *(tem_find(vi_1.begin(), vi_1.end(), 4)) << endl;
    cout << endl;
    cout << "test template copy: " << endl;
    vector<double> vd_2(5);
    cout << "before copy: ";
    for(vector<double>::size_type i = 0; i != vd_2.size(); i ++){
        cout << vd_2[i] << " ";
    }
    cout << endl;
    tem_copy(vd_1.begin(), vd_1.end(), back_inserter(vd_2));
    cout << "after copy: ";
    for(vector<double>::size_type i = 0; i != vd_2.size(); i ++){
        cout << vd_2[i] << " ";
    }
    cout << endl << endl;
    string s = "fangyangisgoodlooking";
    cout << "before replace: " << s << endl;
    tem_replace(s.begin(), s.end(), 'f', 'y');
    cout << "after replace: " << s << endl;
    cout << endl;
    cout << "before reverse: " << s << endl;
    tem_reverse(s.begin(), s.end());
    cout << "after reverse: " << s << endl;
    cout << endl;
    cout << "test binary search" << endl;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "find or not: " << tem_binary_search(v.begin(), v.end(), 3) << endl;
    cout << endl;

    system("pause");
    return 0;
}