#include <iostream>
#include "header.h"

class Solution {
public:
  int getSum(int a, int b) {
    while(b) {
      auto t = (unsigned int)(a & b) << 1;
      a ^= b;
      b = t;
    }
    return a;
  }
};

int main() {
  Solution s;
  cout << s.getSum(1,2) << endl;
  return 0;
}