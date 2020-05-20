#include <iostream>
#include "header.h"

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int index = 0;
    for(int i = 0; i < t.size(); i++) {
      if(s[index] == t[i]) {
        index++;
      }
    }
    return index == s.size();
  }
};

int main() {
  Solution s;
  cout << s.isSubsequence("abc", "ahbgdc") << endl;
  return 0;
}