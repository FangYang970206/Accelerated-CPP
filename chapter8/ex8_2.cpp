#include <iostream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;


template <class In>
bool tem_equal(In b, In e, In b1)
{
    while(b != e){
        if(*b++ != *b1++)
            return false;
    }
    return true;
}

template <class In, class T>
In tem_find(In b, In e, T t)
{
    while(b != e){
        if(*b == t)
            return b;
        else
            ++b;
    }
    return e;
}

template <class In, class Out>
Out tem_copy(In b, In e, Out d)
{
    while(b != e){
        *d++ = *b++;
    }
    return d;
}

template <class In, class Out, class Function>
Out tem_remove_copy_if(In b, In e, Out d, Function f)
{
    while(b != e){
        if(!f(*b))
            *d++ = *b;
        b++;
    }
}

template <class In, class Out, class Function>
void tem_transform(In b, In e, Out d, Function f){
    while(b != e){
        *d++ = f(*b++);
    }
}

template <class In, class T>
T tem_accumulate(In b, In e, T t)
{
    while(b != e)
        t += *b++;
    return t;
}

template <class In, class Out> 
Out tem_search(Out b1, Out e1, In b2, In e2)
{
    for(; b1 != e1; b1++){
        if(tem_equal(b2, e2, b1))
            return b1;
    }
    return e1;
}

template <class In, class T>
In tem_find_if(In b, In e, T t)
{
    while(b != e){
        if(*b == t)
            return b;
        b++;
    }
    return e;
}

template <class In, class Out, class T>
void tem_remove_copy(In b, In e, Out d, T t)
{
    while(b != e){
        if(*b == t)
            *d++ = *b++;
        else
            b++;
    }
}

template <class In, class T>
In tem_remove(In b, In e, T t)
{   
    while(b != e){
        if(*b == t)
            b++;
        else{
            swap(*b, *e);
            int len = ((e-b)-1);
            e = b + len;
        }
    }
    return b;
}

template <class In, class Function>
In tem_partition(In b, In e, Function f)
{   
    while(b != e){
        if(f(*b))
            b++;
        else{
            swap(*b, *(e--));
        }
    }
    return b;
}

template <class T>
void dis_vector(vector<T> v){
    typedef typename vector<T>::const_iterator iter;
    for(iter it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

double square(double t)
{
    return t*t;
}

bool is_two(double x)
{
    return x == 2 ? true : false;
}

bool is_o(char x)
{
    return x == 'o' ? true : false;
}

int main()
{
    cout << "test tem_copy" << endl;
    vector<double> vec1 = {1, 2, 3, 4};
    vector<double> vec2 = vec1;
    vector<double> vec3 = {2, 1, 4, 3};
    cout << "vec1: ";
    dis_vector(vec1);
    cout << "vec2: ";
    dis_vector(vec2);
    cout << "vec3: ";
    dis_vector(vec3);
    cout << "equal vec1 and vec2: " 
         << tem_equal(vec1.begin(), vec1.end(), vec2.begin()) << endl;
    cout << "equal vec1 and vec3: " 
         << tem_equal(vec1.begin(), vec1.end(), vec3.begin()) << endl;

    cout << endl << "test tem_find" << endl;
    cout << "vec1: ";
    dis_vector(vec1);
    string s = tem_find(vec1.begin(), vec1.end(), 3) == vec1.end()? "success" : "fail";
    cout << "find 3 in vec1: " << s << endl;
    s = tem_find(vec1.begin(), vec1.end(), 6) == vec1.end()? "success" : "fail";
    cout << "find 6 in vec1: " << s << endl;

    cout << endl << "test tem_copy" << endl;
    vector<double> vec4;
    tem_copy(vec3.begin(), vec3.end(), back_inserter(vec4));
    cout << "vec4 copy from vec3: ";
    dis_vector(vec4);

    cout << endl << "test tem_remove_copy_if" << endl;
    vector<double> vec5;
    tem_remove_copy_if(vec2.begin(), vec2.end(), back_inserter(vec5), is_two);
    cout << "move all nums(in vec2, not equal to 2) into vec5, display vec5: ";
    dis_vector(vec5);

    cout << endl <<  "test tem_transform" << endl;
    vector<double> vec6;
    tem_transform(vec1.begin(), vec1.end(), back_inserter(vec6), square); 
    cout << "transform vec1 into vec6 by using square, display vec6: ";
    dis_vector(vec6);   

    cout << endl << "test tem_accumulate" << endl;
    dis_vector(vec6);
    cout << "accumulate add vec6, the result: " 
         << tem_accumulate(vec6.begin(), vec6.begin(), 0.0);

    cout << endl << "test tem_search" << endl;
    string s1 = "fangyangisgoodlooking";
    string s2 = "good";
    string s3 = "oodg";
    string flag1 = tem_search(s1.begin(), s1.end(), s2.begin(), s2.end())
                   == s1.end() ? "fail" : "success";
    string flag2 = tem_search(s1.begin(), s1.end(), s3.begin(), s3.end())
                   == s1.end() ? "fail" : "success";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "search s2 in s1, search success or fail: "<< flag1 << endl; 
    cout << "search s3 in s1, search success or fail: "<< flag2 << endl;

    cout << endl << "test tem_find_if" << endl;
    cout << "run tem_find_if(s1.begin(), s1.end(), 'y'), the result: " 
         << *tem_find_if(s1.begin(), s1.end(), 'y') << endl;
    
    cout << endl << "test tem_remove_copy" << endl;
    vector<double> vec7;
    cout << "run tem_remove_copy(vec1.begin(), vec1.end(), back_inserter(vec7), 3)"
         << endl << "the result: ";
    tem_remove_copy(vec1.begin(), vec1.end(), back_inserter(vec7), 3);
    dis_vector(vec7);

    cout << endl << "test tem_remove" << endl;
    cout << "run vec1.erase(tem_remove(vec1.begin(), vec1.end(), 3), vec1.end())" << endl;
    vec1.erase(tem_remove(vec1.begin(), vec1.end(), 3), vec1.end());
    cout << "the result: ";
    dis_vector(vec1);

    cout << endl << "test tem_partition" << endl;
    cout << "run string(tem_partition(s1.begin(), s1.end(), is_o), s1.end()): "
         << string(tem_partition(s1.begin(), s1.end(), is_o), s1.end()) << endl;
    cout << "run string(s1.begin(), tem_partition(s1.begin(), s1.end(), is_o)): "
         << string(s1.begin(), tem_partition(s1.begin(), s1.end(), is_o)) << endl;

    system("pause");
    return 0;
}
