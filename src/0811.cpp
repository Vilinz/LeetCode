#include <iostream>
#include "header.h"

class Solution {
public:
  int waysToChange1(int n) {
    vector<int> coin = {1,5,10,25};
    vector<vector<int>> dp(4, vector<int>(n + 1, 0));
    for(int i = 0; i < 4; i++) {
      dp[i][0] = 1;
    }
    for(int i = 0; i < n  + 1; i++) {
      dp[0][i] = 1;
    }
    for(int i = 1; i < 4; i++) {
      for(int j = 1; j < n + 1; j++) {
        if(j >= coin[i]) {
          dp[i][j] = (dp[i - 1][j] + dp[i][j - coin[i]])%1000000007;
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[3][n];
  }

  int waysToChange(int n) {
    vector<int> coin = {1,5,10,25};
    vector<int> dp(n + 1, 0);
    for(int i = 0; i < n  + 1; i++) {
      dp[i] = 1;
    }
    for(int i = 1; i < 4; i++) {
      for(int j = 1; j < n + 1; j++) {
        if(j >= coin[i]) {
          dp[j] = (dp[j] + dp[j - coin[i]])%1000000007;
        }
      }
    }
    return dp[n];
  }
};

int main() {
  Solution s;
  cout << s.waysToChange(10) << endl;
  return 0;
}