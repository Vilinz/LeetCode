#include <iostream>
#include "header.h"

class Solution {
public:
  bool isMatch(string s, string p) {
    int sSize = s.size(), pSize = p.size();
    vector<vector<int>> dp(sSize + 1, vector<int>(pSize + 1, 0));

    dp[0][0] = 1;

    for(int i = 1; i < sSize; ++i) {
      for(int j = 1; j < pSize; ++j) {
        if(s[i] == p[j] || p[j] == '.') {
          dp[i][j] = dp[]
        }
      }
    }
  }
};

int main() {

  return 0;
}