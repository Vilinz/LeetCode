#include <iostream>
#include "header.h"

class Solution {
public:
  char findTheDifference(string s, string t) {
    char c;
    for(int i = 0; i < s.size(); i++) {
      c ^= s[i];
      c ^= t[i];
    }
    c ^= t[t.size() - 1];
    return c;
  }
};

int main() {
  Solution s;
  cout << s.findTheDifference("abcd", "abcde") << endl;
  return 0;
}