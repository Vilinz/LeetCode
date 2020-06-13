#include <iostream>
#include "header.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0, curr = 0;
        for (auto &i : nums) {
            curr = max(curr + i, i);
            res = max(res, curr);
        }
        return res;
    }
};

int main() {
  Solution s;
  vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(v) << endl;
  return 0;
}