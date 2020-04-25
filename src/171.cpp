#include <iostream>
#include "header.h"

class Solution {
public:
  int titleToNumber(string s) {
    int result = 0;
    for(auto a : s) {
      int num = a - 'A' + 1;
      result = result*26 + num;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.titleToNumber("AB") << endl;
  return 0;
}