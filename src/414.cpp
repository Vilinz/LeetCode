#include <iostream>
#include <set>
#include "header.h"

class Solution {
public:
  int thirdMax(vector<int>& nums) {
    set<int> s;
    for(auto i : nums) {
      s.insert(i);
      if(s.size() > 3) {
        s.erase(*s.begin());
      }
    }
    if(s.size() < 3) {
      return *s.rbegin();
    } else {
      return *s.begin();
    }
  }
};

int main() {
  vector<int> v = {3, 2, 1, 1};
  Solution s;
  cout << s.thirdMax(v) << endl;
  return 0;
}