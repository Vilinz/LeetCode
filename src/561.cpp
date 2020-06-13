#include <iostream>
#include "header.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res{0};
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2) {
            res += nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> v = {1,2,3,4};
    Solution s;
    cout << s.arrayPairSum(v) << endl;
    return 0;
}