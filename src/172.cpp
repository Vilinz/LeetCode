#include <iostream>
#include "header.h"

class Solution {
public:
  int trailingZeroes(int n) {
    int result = {0};
    while(n >= 5) {
      result += n/5;
      n = n/5;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.trailingZeroes(5) << endl;
  return 0;
}