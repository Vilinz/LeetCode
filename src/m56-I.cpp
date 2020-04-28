#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> singleNumbers(vector<int>& nums) {
    int result = 0;
    for(auto n : nums) {
      result ^= n;
    }

    int find = 1;
    while((find & result) == 0) {
      find <<= 1;
    }

    int a = {0}, b = {0};
    for(auto n : nums) {
      if(n & find) {
        a ^= n;
      } else {
        b ^= n;
      }
    }
    return vector<int>{a, b};
  }
};

int main() {
  Solution s;
  vector<int> v = {4, 4, 6, 1};
  vector<int> r = s.singleNumbers(v);
  for(auto n : r) {
    cout << n << ", ";
  }
  cout << endl;
  return 0;
}