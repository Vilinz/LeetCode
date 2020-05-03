#include <iostream>
#include "header.h"

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int result = nums[0], curr = 0;
    for(auto i : nums) {
      curr = max(curr + i, i);
      result = max(result, curr);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
  cout << s.maxSubArray(v) << endl;
  return 0;
}