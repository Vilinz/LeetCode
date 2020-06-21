#include <iostream>
#include "header.h"

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());

        int missing = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                res.push_back(nums[i]);
            }
            if (nums[i] > nums[i - 1] + 1) {
                missing = nums[i - 1] + 1;
            }
        }

        res.push_back(nums[nums.size() - 1] != nums.size() ? nums.size() : missing);
        return res;
    }
};

int main() {
    vector<int> v = {1,5,3,2,2,7,6,4,8,9};
    Solution s;
    vector<int> r = s.findErrorNums(v);
    for (auto &i : r) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}