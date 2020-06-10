#include <iostream>
#include "header.h"

class Solution {
public:
  string reverseStr(string s, int k) {
    for(int i = 0; i < s.size(); i += 2*k) {
      int len = 0;
      if(i + k > s.size()) {
        len = s.size() - i;
      } else {
        len = k;
      }
      string sub = s.substr(i, len);
      reverse(sub.begin(), sub.end());
      s.replace(i, len, sub);
    }
    return s;
  }
};

int main() {
  Solution s;
  cout << s.reverseStr("abcdefg", 2) << endl;
  return 0;
}