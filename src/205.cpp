#include <iostream>
#include "header.h"
#include <unordered_map>

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> sm;
    unordered_map<char, char> tm;
    for (int i = 0; i < s.size(); i++) {
      if (sm.count(s[i]) != 0) {
        if(sm[s[i]] != t[i]) {
          return false;
        }
      } else if (tm.count(t[i])) {
        if(tm[t[i]] != s[i]) {
          return false;
        }
      } else {
        sm[s[i]] = t[i];
        tm[t[i]] = s[i];
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isIsomorphic("abab", "baba") << endl;
  return 0;
}