#include <iostream>
#include "header.h"

class Solution {
public:
    vector<int> rows;
    vector<int> hills;
    vector<int> dales;
    bool check(int n, int currLine, int currIndex) {
        int res = rows[currIndex] + hills[currLine - currIndex + 2 * n] + dales[currLine + currIndex];
        return (res == 0) ? true : false;
    }
    void backtrace(vector<vector<string>> &res, vector<string> &v, int n, int currLine, int &count) {
        if (currLine == n && count == n) {
            res.push_back(v);
            return;
        }
        if (currLine >= n) {
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(n, currLine, i)) {
                v[currLine][i] = 'Q';
                rows[i] = 1;
                hills[currLine - i + 2 * n] = 1;  // "hill" diagonals
                dales[currLine + i] = 1;   //"dale" diagonals
                ++count;
                backtrace(res, v, n, currLine + 1, count);   
                v[currLine][i] = '.';
                --count;
                rows[i] = 0;
                hills[currLine - i + 2 * n] = 0;  // "hill" diagonals
                dales[currLine + i] = 0;   //"dale" diagonals
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> v(n, string(n, '.'));

        rows = vector<int>(n, 0);
        hills = vector<int>(3 * n - 1, 0);
        dales = vector<int>(2 * n - 1, 0);
        int count = 0;
        backtrace(res, v, n, 0, count);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<string>> r = s.solveNQueens(4);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[0].size(); ++j) {
            cout << r[i][j] << endl;
        }
        cout << endl << endl;
    }
    return 0;
}