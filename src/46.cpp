#include <iostream>
#include "header.h"

class Solution {
public:
  void traceback(vector<vector<int>>& res, vector<int>& nums, int first, int len) {
    if(first == len) {
      res.push_back(nums);
      return;
    }

    for(int i = first; i < len; i++) {
      swap(nums[i], nums[first]);
      traceback(res, nums, first + 1, len);
      swap(nums[i], nums[first]);
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      traceback(res, nums, 0, nums.size());
      return res;
  }
};

int main() {
  vector<int> nums = {1,2,3};
  Solution s;
  vector<vector<int>> res = s.permute(nums);
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[0].size(); j++) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}