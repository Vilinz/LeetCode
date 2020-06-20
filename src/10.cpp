#include <iostream>
#include "header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;
        p = " " + p;
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("aa", "a*") << endl;
    return 0;
}