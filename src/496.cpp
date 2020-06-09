#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    map<int, int> m;
    vector<int> r;
    for(int i = 0; i < nums2.size(); ++i) {
      if(s.empty()) {
        s.push(nums2[i]);
        continue;
      }
      while(!s.empty() && nums2[i] > s.top()) {
        m[s.top()] = nums2[i];
        s.pop();
      }
      s.push(nums2[i]);
    }
    while(!s.empty()) {
      m[s.top()] = -1;
      s.pop();
    }
    for(auto &i : nums1) {
      r.push_back(m[i]);
    }
    return r;
  }
};

int main() {
  vector<int> v1 = {4,1,2}, v2 = {1,3,4,2};
  Solution s;
  vector<int> r = s.nextGreaterElement(v1, v2);
  for(auto &i : r) {
    cout << i << endl;
  }
  return 0;
}