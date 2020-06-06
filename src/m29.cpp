#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.empty()) {
      return {};
    }
    int size1 = matrix.size();
    int size2 = matrix[0].size();
    vector<int> dy = {1, 0, -1, 0}, dx = {0, 1, 0, -1};
    vector<vector<bool>> visted(size1, vector<bool>(size2, false));
    vector<int> res;
    int x = 0, y = 0, direction = 0;
    for(int i = 0; i < size1*size2; i++) {
      res.push_back(matrix[x][y]);
      visted[x][y] = true;
      int tx = x + dx[direction], ty = y + dy[direction];
      if(tx < 0 || tx >= size1 || ty < 0 || ty >= size2 || visted[tx][ty]) {
        direction = (direction + 1)%4;
        tx = x + dx[direction];
        ty = y + dy[direction];
      }
      x = tx;
      y = ty;
    }
    
    return res;
  }
};

int main() {
  vector<vector<int>> v = {{1,2,3, 3},{4,5,6,6},{7,8,9,9}, {10,11,12,13}};
  Solution s;
  vector<int> r = s.spiralOrder(v);
  for(auto &i : r) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}