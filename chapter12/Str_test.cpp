#include <iostream>
#include "Str.hpp"

using namespace std;

int main()
{
    cout << "test Str initial, iterator and iostream" << endl;
    Str s0 = "fangyang";
    Str s1("fangyang");
    Str s2(s0.begin(), s0.end());
    Str s3(5, 'z');
    Str s4 = s1;
    Str s5(s3);
    cout << "s0: " << s0 << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    cout << "s5: " << s5 << endl;

    cout << endl << "test size and index" << endl;
    cout << "s1.size(): " << s1.size() << endl;
    cout << "s1[4]: " << s1[4] << endl;

    cout << endl << "test Str c_str, data and copy" << endl;
    cout << "s1.c_str(): " << s1.c_str() << endl;
    cout << "s1.data(): " << s1.data() << endl;
    s1.copy(s5.end(), 4, 4);
    char buf[10] = {0};
    s1.copy(buf, 5);
    cout << "s1.copy(buf, 5), buf: " << buf << endl;

    cout << endl << "test relations operator" << endl;
    cout << "(s1 == s2): " << (s1 == s2) << endl;
    cout << s1.size() << " " << s2.size() << endl;
    cout << "(s3 > s1): " << (s3 > s1) << endl;
    cout << "(s1 < s3): " << (s1 < s3) << endl; 
    cout << "(s3 >= s1): " << (s3 >= s1) << endl;
    cout << "(s1 >= s2): " << (s1 >= s2) << endl;
    cout << "(s1 <= s3): " << (s1 <= s3) << endl;
    cout << "(s1 <= s2): " << (s1 == s2) << endl;

    cout << endl << "test add operator" << endl;
    cout << "s1 + s2: " << (s1 + s2) << endl;
    cout << "yeah + s1: " << ("yeah" + s1) << endl;
    cout << "s1 + yeah" << (s1 + "yeah") << endl;
    s3 += s4;
    cout << "s3 += s4, s3:" << s3 << endl;
    
    cout << endl << "test getline and insert" << endl;
    cout << "please enter str: ";
    getline(cin, s1);
    cout << "getline(cin, s1), s1:" << s1 << endl;
    s1.insert(s1.begin(), s2.begin(), s2.begin()+4);
    cout << "s1.insert(s1.begin(), s2.begin(), s2,begin()+4), s1: " << s1 << endl;

    cout << "test Str as condition and ostream_iterator" << endl;
    if(s1)cout << "s1 is not empty" << endl;
    Str s6;
    if(s6)cout << "s6 is empty" << endl;
    ostream_iterator<char> osi(cout, " ");
    osi << s1;
    system("pause");
    return 0;
}