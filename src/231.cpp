#include <iostream>
#include "header.h"

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if(n == 0) {
      return false;
    }
    while(n) {
      if(n % 2 == 0 || n == 1) {
        n /= 2;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPowerOfTwo(1) << endl;
  return 0;
}