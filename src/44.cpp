#include <iostream>
#include "header.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        vector<vector<int>> dp(sSize + 1, vector<int>(pSize + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < pSize; ++i) {
            if (p[i] == '*' && dp[0][i]) {
                dp[0][i + 1] = dp[0][i];
            }
        }

        for (int i = 0; i < sSize; ++i) {
            for (int j = 0; j < pSize; ++j) {
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i + 1][j + 1] = dp[i][j];
                } else if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i][j] || dp[i + 1][j];
                }
            }
        }
        return dp[sSize][pSize];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("adceb", "*a*b") << endl;
    return 0;
}