//code from https://github.com/bitsai/book-exercises/blob/master/Accelerated%20C%2B%2B/chapter07/7-9.cpp
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdexcept>


using namespace std;

#define MY_RAND_MAX 32767

/*
    two choices: 
    1. n < MY_RAND_MAX, divided MY_RAND_MAX into n stacks, use the same
    interval to replace possibility;
    2. n > MY_RAND_MAX, divided n into s stacks, each stack has MY_RAND_MAX
    size. rand(s-1) multiply MY_RAND_MAX + rand(MY_RAND_MAX) can achieve rand(n).
*/

int nrand(int n) {
  if (n <= 0)
    throw domain_error("Argument to nrand is out of range");
  
  int r;

  if (n <= MY_RAND_MAX) {						       
    const int bucket_size = MY_RAND_MAX / n;

    do {
      int bucket = rand() / bucket_size;
      r = bucket;
    } while (r >= n);
  } else {
    const int bucket_size = ceil(n / MY_RAND_MAX);

    do {
      const int bucket = nrand(MY_RAND_MAX);
      const int remainder = nrand(bucket_size);
      r = (bucket - 1) * bucket_size + remainder;
    } while (r >= n);
  }

  return r;
}


int main() {
  int limit;

  while (cin >> limit)
    cout << nrand(limit) << endl;

  return 0;
}