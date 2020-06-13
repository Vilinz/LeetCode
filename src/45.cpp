#include <iostream>
#include "header.h"

class Solution {
public:
  int jump(vector<int>& nums) {
    if(nums.size() == 1 || nums.size() == 0) {
      return 0;
    }
    int count = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(i + nums[i] >= nums.size() - 1) {
        return ++count;
      }

      int max = i + nums[i];
      int j = 1, index = nums[i];
      for(; j <= nums[i]; j++) {
        if(i + j + nums[i + j] > max) {
          max = i + j + nums[i + j];
          index = j;
        }
      }
      i = i + index - 1;
      count++;
    }
    return count;
  }
};

int main() {
  Solution s;
  vector<int> v = {2,3,1,1,4};
  cout << s.jump(v) << endl;
  return 0;
}