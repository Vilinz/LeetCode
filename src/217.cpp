#include <iostream>
#include <set>
#include "header.h"

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> s;
    for(int i = 0; i < nums.size(); i++) {
      s.insert(nums[i]);
      if(s.size() != i + 1) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  vector<int> v = {1,2};
  Solution s;
  cout << s.containsDuplicate(v) << endl;
  return 0;
}