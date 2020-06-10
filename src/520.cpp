#include <iostream>
#include "header.h"

class Solution {
public:
  bool detectCapitalUse(string word) {
    int flag1 = 0, flag2 = 0, flag3 = 0;
    for(int i = 0; i < word.size() && (flag1 == 0 || flag2 == 0 || flag3 == 0); ++i) {
      if(isupper(word[i])) {
        flag2 = 1;
        if(i != 0) {
          flag3 = 1;
        }
      } else {
        flag1 = 1;
      }
    }
    return (flag1 == 0 || flag2 == 0 || flag3 == 0);
  }
};

int main() {
  Solution s;
  cout << s.detectCapitalUse("leetcode") << endl;
  return 0;
}