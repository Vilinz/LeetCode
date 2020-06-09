#include <iostream>
#include "header.h"

class Solution {
public:
  int translateNum(int num) {
    int p = 0, q = 0, r = 1;
    string str = to_string(num);
    for(int i = 0; i < str.size(); ++i) {
      p = q;
      q = r;
      r = q;
      if(i == 0) {
        continue;
      }
      string subStr = str.substr(i - 1, 2);
      if(subStr <= "25" && subStr >= "10") {
        r += p;
      }
    }
    return r;
  }
};

int main() {
  Solution s;
  cout << s.translateNum(12258) << endl;
  return 0;
}