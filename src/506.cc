#include <iostream>
#include "header.h"

class MyNode {
public:
  int index;
  int score;
  MyNode(int i, int s) : index(i), score(s) {}
  bool operator<(MyNode &n) {
    return score > n.score;
  }
};

class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<MyNode> v;
    for(int i = 0; i < nums.size(); ++i) {
      v.push_back({i, nums[i]});
    }
    sort(v.begin(), v.end());
    vector<string> r(nums.size());
    for(int i = 0; i < v.size(); ++i) {
      if(i == 0) {
        r[v[i].index] = "Gold Medal";
      } else if(i == 1) {
        r[v[i].index] = "Silver Medal";
      } else if(i == 2) {
        r[v[i].index] = "Bronze Medal";
      } else {
        r[v[i].index] = to_string(i);
      }
    }
    return r;
  }
};

int main() {
  vector<int> v = {5, 4, 3, 2, 1};
  Solution s;
  vector<string> r = s.findRelativeRanks(v);
  for(auto &i : r) {
    cout << i << endl;
  }
  return 0;
}