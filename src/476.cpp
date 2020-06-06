#include <iostream>
#include "header.h"

class Solution {
public:
  int findComplement(int num) {
    int res = 0;
    int count = 0;
    while(num) {
      res += !(num & 1) << count;
      num >>= 1;
      count++;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.findComplement(5) << endl;
  return 0;
}