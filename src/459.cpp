#include <iostream>
#include "header.h"

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int size = s.size();
    for(int i = 1; i <= size/2; i++) {
      if(s[i] != s[0]) {
        continue;
      }
      string str = s.substr(0, i);
      int index = i;
      bool flag = 0;
      while(index < size) {
        if(s.substr(index, i) == str) {
          index += i;
          continue;
        }
        flag = 1;
        index += i;
      }
      if(flag == 0) {
        return true;
      }
    }
    return false;
  }
  /*
  bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
  */
};

int main() {
  Solution s;
  cout << s.repeatedSubstringPattern("abcabcabcabc") << endl;
  return 0;
}