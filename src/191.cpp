#include <iostream>
#include "header.h"

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while(n) {
      if(n & 1 == 1) {
        count++;
      }
      n = n >> 1;
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.hammingWeight(11) << endl;
  return 0;
}