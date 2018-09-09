#include <iostream>
#include <vector>

using std::cout;   using std::cin;
using std::endl;   using std::vector;


int main()
{
    vector<double> vec;
    typedef vector<double>::size_type vec_sz;
    double x, result = 0;
    cout << "please enter double numbers: ";
    while(cin >> x)
    {
        vec.push_back(x);
    }
    vec_sz size = vec.size();
    for(vec_sz i = 0; i != size; i++)
    {
        result += vec[i];
    }
    cout << "the median of vector<double> is: " << result/size << endl;

    system("pause");
    return 0;
}