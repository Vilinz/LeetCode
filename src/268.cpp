#include <iostream>
#include "header.h"

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int realSum = 0, sum = 0;
    for(int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    realSum = (1 + nums.size())*nums.size()/2;
    return realSum - sum;
  }
};

int main() {
  vector<int> v = {3,0,1};
  Solution s;
  cout << s.missingNumber(v) << endl;
  return 0;
}