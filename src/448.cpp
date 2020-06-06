#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
      int temp = abs(nums[i]) - 1;
      if(nums[temp] > 0) {
        nums[temp] = -nums[temp];
      }
      
    }
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] >= 0) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};

int main() {
  vector<int> v = {4,3,2,7,8,2,3,1};
  Solution s;
  vector<int> r = s.findDisappearedNumbers(v);
  for(auto a : r) {
    cout << a << ", ";
  }
  cout << endl;
  return 0;
}