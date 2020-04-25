#include <iostream>
#include "header.h"

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int maxNum = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(i <= maxNum) {
        maxNum = max(maxNum, nums[i] + i);
        if(maxNum >= nums.size() - 1) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> v{2,3,1,1,4};
  cout << s.canJump(v) << endl;
  return 0;
}