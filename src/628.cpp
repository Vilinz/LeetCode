#include <iostream>
#include "header.h"

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        return max(nums[0] * nums[1] * nums[nums.size() - 1]
                    , nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
    }
};

int main() {
    vector<int> v = {1,2,3,4};
    Solution s;
    cout << s.maximumProduct(v) << endl;
    return 0;
}