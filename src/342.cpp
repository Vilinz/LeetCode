#include <iostream>
#include "header.h"

class Solution {
public:
  bool isPowerOfFour(int num) {
    int count = 0;
    while(num > 1) {
      if(num&1) {
        break;
      }
      num >>= 1;
      count++;
    }
    return (num == 1) && count % 2 == 0;
  }
};

int main() {
  Solution s;
  cout << s.isPowerOfFour(20) << endl;
  return 0;
}