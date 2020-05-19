#include <iostream>
#include "header.h"

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int maxNum = nums[0], minNum = nums[0], res = nums[0];
    for(int i = 1; i < nums.size(); i++) {
      int maxTemp = maxNum, minTemp = minNum;
      maxNum = max(minTemp * nums[i], max(nums[i], maxTemp * nums[i]));
      minNum = min(minTemp * nums[i], min(nums[i], maxTemp * nums[i]));
      res = max(res, maxNum);
    }
    return res;
  }
};

int main() {
  vector<int> v = {2,3,-2,4};
  Solution s;
  cout << s.maxProduct(v) << endl;
  return 0;
}