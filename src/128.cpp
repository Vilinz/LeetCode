#include <iostream>
#include <unordered_set>
#include "header.h"

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int maxLen = 0;
    unordered_set<int> s(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++) {
      if(!s.count(nums[i] - 1)) {
        int currentLen = 1;
        while(s.count(nums[i] + currentLen)) {
          ++currentLen;
        }
        maxLen = max(maxLen, currentLen);
      }
    }
    return maxLen;
  }
};

int main() {
  vector<int> v = {100, 4, 200, 1, 3, 2};
  Solution s;
  cout << s.longestConsecutive(v) << endl;
  return 0;
}