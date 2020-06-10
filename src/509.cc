#include <iostream>
#include "header.h"

class Solution {
public:
  int fib(int N) {
    if(N == 0) {
      return 0;
    } else if(N == 1) {
      return 1;
    }
    return fib(N - 1) + fib(N - 2);
  }
};

int main() {
  Solution s;
  cout << s.fib(4) << endl;
  return 0;
}