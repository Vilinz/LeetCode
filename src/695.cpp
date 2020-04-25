#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  int maxCount = 0;
public:
  int dfs(int i, int j, vector<vector<int>> &grid) {
    int width = grid.size(), height = grid[0].size();
    if(i < 0 || i >= width || j < 0 || j >= height || grid[i][j] == 0) {
      return 0;
    }
    grid[i][j] = 0;
    int tempCount = 1;
    tempCount += dfs(i - 1, j, grid);
    tempCount += dfs(i + 1, j, grid);
    tempCount += dfs(i, j - 1, grid);
    tempCount += dfs(i, j + 1, grid);
    return tempCount;
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int width = grid.size(), height = grid[0].size();
    for(int i = 0; i < width; i++) {
      for(int j = 0; j < height; j++) {
        if(grid[i][j] == 1) {
          int c = dfs(i, j, grid);
          if(c > maxCount) {
            maxCount = c;
          }
        }
      }
    }
    return maxCount;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a{
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
  };
  cout << s.maxAreaOfIsland(a) << endl;
  return 0;
}