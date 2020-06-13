#include <iostream>
#include <set>
#include "header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int target = 0 - nums[i];
            int begin = i + 1, end = nums.size() - 1;
            while (begin < end) {
                if (nums[begin] + nums[end] == target) {
                    vector<int> temp = {nums[i], nums[begin], nums[end]};
                    res.insert(temp);
                    ++begin;
                    --end;
                } else if (nums[begin] + nums[end] < target) {
                    ++begin;
                } else {
                    --end;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

int main() {
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> r = s.threeSum(v);
    for (auto &i : r) {
        for (auto &j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }
    return 0;
}