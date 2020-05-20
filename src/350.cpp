#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    vector<int> res;
    for(auto i : nums1) {
      m[i]++;
    }

    for(auto i : nums2) {
      if(m.count(i) && m[i] > 0) {
        res.push_back(i);
        m[i]--;
      }
    }
    return res;
  }
};

int main() {
  vector<int> m1 = {1,2,2,1};
  vector<int> m2 = {2,2};
  Solution s;
  vector<int> r = s.intersect(m1,m2);
  for(auto a : r) {
    cout << a << ", ";
  }
  cout << endl;
  return 0;
}