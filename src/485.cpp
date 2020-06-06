#include <iostream>
#include "header.h"

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int r = 0, temp = 0;
    for(size_t i = 0; i < nums.size(); ++i) {
      if(nums[i] == 0) {
        r = max(r, temp);
        temp = 0;
      } else {
        ++temp;
      }
    }
    r = max(r, temp);
    return r;
  }
};

int main() {
  vector<int> v = {1,1,1,0,0,1,0,1,1,1,1,0};
  Solution s;
  cout << s.findMaxConsecutiveOnes(v) << endl;
  return 0;
}