#include <iostream>
#include "header.h"

class Solution {
public:
  int length(vector<vector<int>>& grid, int i, int j, vector<int> &dx, vector<int> &dy) {
    int temp = 4;
    for(int m = 0; m < 4; m++) {
      int ix = i + dx[m], iy = j + dy[m];
      if(ix < 0 || ix >= grid.size() || iy < 0 ||iy >= grid[0].size()) {
        continue;
      }
      if(grid[ix][iy] == 1) {
        --temp;
      }
    }
    return temp;
  }
  int islandPerimeter(vector<vector<int>>& grid) {
    int count = 0;
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[0].size(); ++j) {
        if(grid[i][j] == 1) {
          count += length(grid, i, j, dx, dy);
        }
      }
    }
    return count;
  }
};

int main() {
  vector<vector<int>> v = 
  {{0,1,0,0},
  {1,1,1,0},
  {0,1,0,0},
  {1,1,0,0}};
  Solution s;
  cout << s.islandPerimeter(v) << endl;
  return 0;
}