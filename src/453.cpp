#include <iostream>
#include "header.h"
#include <climits>

class Solution {
public:
  int minMoves(vector<int>& nums) {
    int m = INT_MAX;
    int moves = 0;
    for(int i = 0; i < nums.size(); i++) {
      m = min(m, nums[i]);
    }

    for(int i = 0; i < nums.size(); ++i) {
      moves += nums[i] - m;
    }
    return moves;
  }
};

int main() {
  vector<int> v = {1, 2, 3};
  Solution s;
  cout << s.minMoves(v) << endl;
  return 0;
}