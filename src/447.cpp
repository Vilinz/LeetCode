#include <iostream>
#include "header.h"

class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    vector<unordered_map<int, int>> m(points.size(), unordered_map<int,int>());
    for(int i = 0; i < points.size(); i++) {
      for(int j = i + 1; j < points.size(); j++) {
        int dis = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1] , 2);
        res += m[i][dis] * 2 + m[j][dis] * 2;
        m[i][dis]++;
        m[j][dis]++;
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> v = {{0,0},{1,0},{2,0}};
  Solution s;
  cout << s.numberOfBoomerangs(v) << endl;
  return 0;
}