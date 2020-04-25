#include <iostream>
#include "header.h"

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    int i = 32;
    while(n) {
      int temp = n & 1;
      n = n >> 1;
      i--;
      if(temp == 0) {
        continue;
      }
      result += pow(2, i);
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.reverseBits(43261596) << endl;
  return 0;
}