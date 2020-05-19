#include <iostream>
#include <set>
#include <iterator> 
#include "header.h"

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    set<int> s1(nums1.begin(), nums1.end());
    set<int> s2(nums2.begin(), nums2.end());
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), insert_iterator<vector<int>> (res, res.begin()));
    return res;
  }
};

int main() {

  return 0;
}