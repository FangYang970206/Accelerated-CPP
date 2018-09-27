#include <iostream>
#include <string>
#include "ex10_4.hpp"

using namespace std;

int main()
{
    string arr[] = {"hello", "fang", "yang"};
    list<string> a = list<string>(arr, arr+3);
    list<string>::const_iterator i = a.begin();
    //test equality
    if(a.begin() == a.begin())
        cout << "the begining" << endl;
    //test inequality
    if(a.begin() != a.end())
        cout << "begin is not end" << endl;
    //test empty or not
    if(!a.empty())
        cout << "list isn't empty." << endl;
    //test list size
    cout << "the size of list: " << a.size() << endl;
    //test dereference
    cout << *i << endl;
    cout << i->size() << endl;
    //test increment
    ++i;
    cout << *i << endl;
    i++;
    cout << *i << endl;
    //test decrement
    --i;
    cout << *i << endl;
    i--;
    cout << *i << endl;

    system("pause");
    return 0;

}