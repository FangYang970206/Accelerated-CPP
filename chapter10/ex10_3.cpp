#include <iostream>
#include <iterator>
#include "ex10_2.hpp"


int main()
{
    double test_array[] = {1, 3, 2, 6, 4, 8, 5, 9, 7};
    vector<double> test_vector = {1, 3, 2, 6, 4, 8, 5, 9, 7};
    size_t array_size = sizeof(test_array)/sizeof(*test_array); 
    double median_array = median<double>(test_array, test_array+array_size);
    double median_vector = median<double>(test_vector.begin(), test_vector.end());
    copy(test_array, test_array+array_size, ostream_iterator<double>(cout, " "));
    cout << "test array: " << median_array << endl;
    copy(test_vector.begin(), test_vector.end(), ostream_iterator<double>(cout, " "));
    cout << "test vector: " << median_vector << endl;
    system("pause");
    return 0;
}