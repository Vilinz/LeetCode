#include <iostream>
#include "header.h"

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int gIndex = 0, sIndex = 0;
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] >= g[gIndex]) {
        ++gIndex;
        ++count;
        if(gIndex >= g.size()) {
          return count;
        }
      }
    }
    return count;
  }
};

int main() {
  vector<int> v1 = {1,2}, v2 = {1, 2, 3};
  Solution s;
  cout << s.findContentChildren(v1, v2) << endl;
  return 0;
}