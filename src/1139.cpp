#include <iostream>
#include "header.h"

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int width = grid.size(), height = grid[0].size();
        vector<vector<int>> up(width, vector<int>(height, 0));
        vector<vector<int>> left(width, vector<int>(height, 0));

        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (i != 0 && grid[i - 1][j] == 1) {
                    up[i][j] = up[i - 1][j] + grid[i][j];
                } else {
                    up[i][j] = grid[i][j];
                }

                if (j != 0 && grid[i][j - 1] == 1) {
                    left[i][j] = left[i][j - 1] + grid[i][j];
                } else {
                    left[i][j] = grid[i][j];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (grid[i][j] == 1) {
                    int minLen = min(up[i][j], left[i][j]);
                    while (minLen > res) {
                        if (up[i][j - minLen + 1] >= minLen && left[i - minLen + 1][j] >= minLen) {
                            res = minLen;
                            break;
                        }
                        minLen--;
                    }
                }
            }
        }
        return res * res;
    }
};

int main() {
    vector<vector<int>> v = {{1,1,1},{1,0,1},{1,1,1}};
    Solution s;
    cout << s.largest1BorderedSquare(v) << endl;
    return 0;
}