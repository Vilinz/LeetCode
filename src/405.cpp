#include <iostream>
#include "header.h"

class Solution {
public:
  string toHex(int num) {
    string m = "0123456789abcdef";
    if(num == 0) {
      return "0";
    }
    uint32_t n = num;
    string res;
    while(n) {
      res += m[n - ((n>>4) << 4)];
      n >>= 4;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  cout << s.toHex(-1) << endl;
  return 0;
}