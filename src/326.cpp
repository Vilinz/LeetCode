#include <iostream>
#include "header.h"

class Solution {
public:
  bool isPowerOfThree(int n) {
    if(n < 1) {
      return false;
    }
    double res = log10(n) / log10(3);
    return res - (int)res > 0 ? false : true;
  }
};

int main() {
  Solution s;
  cout << s.isPowerOfThree(26) << endl;
  return 0;
}