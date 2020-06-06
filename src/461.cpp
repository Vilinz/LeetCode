#include <iostream>
#include "header.h"

class Solution {
public:
  int hammingDistance(int x, int y) {
    int count = 0;
    int temp = x ^ y;
    while(temp) {
      if(temp & 1) {
        ++count;
      }
      temp >>= 1;
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.hammingDistance(1, 4) << endl;
  return 0;
}