#include <iostream>
#include <unordered_set>
#include "header.h"

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> s;
    for(int i = 0; i < nums.size(); i++) {
      if (s.count(nums[i])) {
        return true;
      }
      if(s.size() == k + 1) {
        s.erase(nums[i - k]);
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> v = {1,2,3,1};
  cout << s.containsNearbyDuplicate(v, 2) << endl;
  return 0;
}