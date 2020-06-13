#include <iostream>
#include "header.h"

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty()) {
            return {{}};
        }

        int width = nums.size(), height = nums[0].size();
        if (width * height != r * c) {
            return nums;
        }

        vector<vector<int>> res;
        vector<int> row;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                row.push_back(nums[i][j]);
                if (row.size() == c) {
                    res.push_back(row);
                    row.clear();
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> v = {{1,2},{3,4}};
    Solution s;
    vector<vector<int>> r = s.matrixReshape(v, 1, 4);
    for (auto &i : r) {
        for (auto &j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }
    return 0;
}