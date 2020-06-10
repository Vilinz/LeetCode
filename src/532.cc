#include <iostream>
#include <set>
#include "header.h"

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    int count = 0;
    sort(nums.begin(), nums.end());
    for(auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
      for(auto it2 = it1 + 1; it2 != nums.end(); ++it2) {
        if(*it2 - *it1 == k) {
          ++count;
          while(it2 + 1 != nums.end() && *it2 == *(it2 + 1)) {
            ++it2;
          }
          while(it1 + 1 != nums.end() && *it1 == *(it1 + 1)) {
            ++it1;
          }
        }
        if(*it2 - *it1 > k) {
          break;
        }
      }
    }
    return count;
  }
};

int main() {
  vector<int> v = {3, 1, 1, 1, 5};
  Solution s;
  cout << s.findPairs(v, 0) << endl;
  return 0;
}