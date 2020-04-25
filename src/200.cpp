#include <iostream>
#include "header.h"

class Solution {
private:
  vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
public:
  void recVisit(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited) {
    if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || grid[i][j] == '0' || visited[i][j] == 1) {
      return;
    }
    visited[i][j] = 1;
    recVisit(i + dirs[0][0], j + dirs[0][1], grid, visited);
    recVisit(i + dirs[1][0], j + dirs[1][1], grid, visited);
    recVisit(i + dirs[2][0], j + dirs[2][1], grid, visited);
    recVisit(i + dirs[3][0], j + dirs[3][1], grid, visited);
  }
  int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) {
      return 0;
    }
    int count = 0;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    for(int i = 0; i < grid.size(); i++) {
      for(int j = 0; j < grid[0].size(); j++) {
        if(visited[i][j] == 0 && grid[i][j] == '1') {
          count++;
          recVisit(i, j, grid, visited);
        }
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  vector<vector<char>> c{
    {'1','1','0','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };
  cout << s.numIslands(c) << endl;
  return 0;
}