#include <iostream>
#include "header.h"

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    /*
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i = i + 2) {
      if(nums[i] != nums[i - 1]) {
        if(i == 1) {
          return nums[0];
        }
        return nums[i - 1];
      }
    }
    return nums[nums.size() - 1];
    */
   int result = 0;
   for(auto i : nums) {
     result ^= i;
   }
   return result;
  }
};

int main() {
  Solution s;
  vector<int> v{0,2,0,1,2};
  cout << s.singleNumber(v) << endl;
  return 0;
}