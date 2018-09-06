#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using std::cin;    using std::setprecision;
using std::cout;   using std::string;
using std::endl;   using std::streamsize;
using std::vector; using std::sort;
using std::cerr;


int main()
{
    vector<int> int_set;
    int x;

    cout << "please enter integer set, the size of integer set must divide by four: ";

    while(cin >> x)
    {
        int_set.push_back(x);
    }

    if(int_set.size() % 4 != 0){
        cerr << "the size of integer set can't divide by four, please enter again!"<<endl;
        return 1;
    }

    const vector<int>::size_type size = int_set.size();
    sort(int_set.begin(), int_set.end());
    
    for(vector<int>::size_type i = size; i != 0;  i--)
    {
        if(i==size)
            cout << "first section: " ;
        else {
            if(i==size/4*3){
                cout << endl;
                cout << "second section: " ;
            }
            else {
                if(i==size/2){
                    cout << endl;
                    cout << "third section: ";
                }
                else {
                    if(i==size/4){
                        cout << endl;
                        cout << "fourth section: ";
                    }
                }
            }
        }
        cout << int_set[i-1]<< " ";
    }

    system("pause");
    
    return 0;
}