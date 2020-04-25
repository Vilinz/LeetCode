#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  vector<vector<int>> updateMatrix1(vector<vector<int>>& matrix) {
    int dirs[4][2] = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size()));
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size()));
    queue<pair<int, int>> q;
    int h = matrix.size(), w = matrix[0].size();
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(matrix[i][j] == 0) {
          q.emplace(i, j);
          visited[i][j] = 1;
        }
      }
    }

    while(!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      for(int k = 0; k < 4; k++) {
        int i0 = i + dirs[k][0];
        int i1 = j + dirs[k][1];
        if(i0 >= 0 && i0 < h && i1 >= 0 && i1 < w && visited[i0][i1] == 0) {
          result[i0][i1] = result[i][j] + 1;
          q.emplace(i0, i1);
          visited[i0][i1] = 1;
        }
      }
    }
    return result;
  }

  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> result(m, vector<int>(n, INT_MAX/2));
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(matrix[i][j] == 0) {
          result[i][j] = 0;
        }
      }
    }

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(i - 1 >= 0) {
          result[i][j] = min(result[i][j], result[i - 1][j] + 1);
        }
        if(j - 1 >= 0) {
          result[i][j] = min(result[i][j], result[i][j - 1] + 1);
        }
      }
    }

    for(int i = m - 1; i >= 0; i--) {
      for(int j = n - 1; j >= 0; j--) {
        if(i + 1 < m) {
          result[i][j] = min(result[i][j], result[i + 1][j] + 1);
        }
        if(j + 1 < n) {
          result[i][j] = min(result[i][j], result[i][j + 1] + 1);
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  vector<vector<int>> r = s.updateMatrix(v);
  for(int i = 0; i < r.size(); i++) {
    for(int j = 0; j < r[0].size(); j++) {
      cout << r[i][j] << endl;
    }
  }
  return 0;
}