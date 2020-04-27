#include <iostream>
#include "header.h"

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
      int middle = (left + right)/2;
      if(nums[middle] == target) {
        return middle;
      }

      if(nums[middle] < nums[right]) {
        if(nums[middle] < target && nums[right] >= target) {
          left = middle + 1;
        } else {
          right = middle - 1;
        }
      } else {
        if(nums[middle] > target && nums[left] <= target) {
          right = middle - 1;
        } else {
          left = middle + 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  vector<int> v = {4,5,6,7,0,1,2};
  Solution s;
  cout << s.search(v, 0) << endl;
  return 0;
}