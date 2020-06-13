#include <iostream>
#include "header.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        int direction = 0, row = 0, col = 0;
        for (int i = 0; i < n * n; ++i) {
            res[row][col] = count++;
            int tmpRow = row + dir[direction][0];
            int tmpCol = col + dir[direction][1];
            if (tmpRow < 0 || tmpRow >= n || tmpCol < 0 || tmpCol >= n || res[tmpRow][tmpCol] != 0) {
                direction = (direction + 1) % 4;
            }
            row += dir[direction][0];
            col += dir[direction][1];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> r = s.generateMatrix(3);
    for (auto &i : r) {
        for (auto &j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }
    return 0;
}