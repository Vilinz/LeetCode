#include <iostream>
#include "header.h"

class Solution {
public:
  bool checkRecord(string s) {
    int flag = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == 'A') {
        ++flag;
        if(flag > 1) {
          return false;
        }
      } else if(s[i] == 'L') {
        if(i - 2 >= 0 && s[i - 2] == 'L' && s[i - 1] == 'L') {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.checkRecord("PPALLLP") << endl;
  return 0;
}