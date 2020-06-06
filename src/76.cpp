#include <iostream>
#include "header.h"
#include <climits>

class Solution {
private:
  unordered_map<char, int> cnt, ori;
public:
  bool isSubstr(){
    for(auto c : ori) {
      if(cnt[c.first] < c.second) {
        return false;
      }
    }
    return true;
  }
  string minWindow(string s, string t) {
    int left = 0, right = -1;
    int ansL = -1, len = INT_MAX;
    for(auto c : t) {
      ++ori[c];
    }
    while(right < int(s.size())) {
      if(ori.find(s[++right]) != ori.end()) {
        ++cnt[s[right]];
      }

      while(isSubstr() && left <= right) {
        if(right - left + 1 < len) {
          len = right - left + 1;
          ansL = left;
        }
        if(ori.find(s[left]) != ori.end()) {
          --cnt[s[left]];
        }
        left++;
      }
    }
    return ansL == -1 ? string() : s.substr(ansL, len);
  }
};

int main() {
  Solution s;
  cout << s.minWindow("ADOBECODEBANC","ABC") << endl;
  return 0;
}