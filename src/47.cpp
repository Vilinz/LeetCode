#include <iostream>
#include "header.h"

class Solution {
public:
    void backtrace(vector<int> &nums, vector<vector<int>> &res, int first) {
        if (first == nums.size()) {
            res.push_back(nums);
            return;
        }

        vector<int> temp;
        for (int i = first; i < nums.size(); ++i) {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
                continue;
            }
            temp.push_back(nums[i]);
            swap(nums[i], nums[first]);
            backtrace(nums, res, first + 1);
            swap(nums[i], nums[first]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int first = 0;
        backtrace(nums, res, first);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,1};
    vector<vector<int>> r = s.permuteUnique(v);
    for (int i = 0; i < r.size(); ++i) {
        for (int j = 0; j < r[0].size(); ++j) {
            cout << r[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}