#include <iostream>
#include "header.h"

class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    vector<int> index(nums.size() + 2, 0);
    int cnt = 0, result = 0;
    for(int i = 0; i < nums.size(); i++) {
      if(nums[i] & 1) {
        index[++cnt] = i;
      }
    }
    index[0] = -1;
    index[++cnt] = nums.size();
    for(int i = 1; i + k <= cnt; i++) {
      result += (index[i] - index[i - 1])*(index[i + k] - index[i + k - 1]);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v{1,1,2,1,1};
  cout << s.numberOfSubarrays(v, 3) << endl;
  return 0;
}