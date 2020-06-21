#include <iostream>
#include <numeric>
#include "header.h"

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() < k) {
            double t = accumulate(nums.begin(), nums.end(), 0);
            return t / nums.size();
        }
        double sum = 0.0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};

int main() {
    vector<int> v = {1,12,-5,-6,50,3};
    Solution s;
    cout << s.findMaxAverage(v, 4) << endl;
    return 0;
}