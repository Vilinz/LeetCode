#include <iostream>
#include "header.h"

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int zeroP = 0, nonZeroP = 0;
    while(nonZeroP < nums.size()) {
      while(zeroP < nums.size() && nums[zeroP] != 0) {
        zeroP++;
      }
      while(nonZeroP < nums.size() && nums[nonZeroP] == 0 || zeroP > nonZeroP) {
        nonZeroP++;
      }

      if(zeroP < nums.size() && nonZeroP < nums.size() && zeroP < nonZeroP) {
        int temp = nums[zeroP];
        nums[zeroP] = nums[nonZeroP];
        nums[nonZeroP] = temp;
      }
      
      zeroP++;
      nonZeroP++;
    }
  }
};

int main() {
  vector<int> v = {0, 1};
  Solution s;
  s.moveZeroes(v);
  for(auto a : v) {
    cout << a << ", ";
  }
  cout << endl;
  return 0;
}