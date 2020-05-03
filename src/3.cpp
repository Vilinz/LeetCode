#include <iostream>
#include "header.h"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int result = 0, j = 0;
    for(int i = 0; i < s.size(); i++) {
      while(j < s.size() && set.count(s[i]) != 0) {
        set.erase(s[j]);
        j++;
      }
      result = max(result, i - j + 1);
      set.insert(s[i]);
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
  return 0;
}