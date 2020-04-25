#include <iostream>
#include "header.h"

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if(numRows == 0) {
      return vector<vector<int>>();
    }
    if(numRows == 1) {
      return vector<vector<int>>{{1}};
    }
    if(numRows == 2) {
      return vector<vector<int>>{{1}, {1, 1}};
    }
    vector<vector<int>> result{{1}, {1, 1}};
    for(int i = 1; i < numRows - 1; i++) {
      vector<int> temp{1};
      for(int j = 0; j < result[i].size() - 1; j++) {
        temp.push_back(result[i][j] + result[i][j+1]);
      }
      temp.push_back(1);
      result.push_back(temp);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> r = s.generate(5);
  for(int i = 0; i < r.size(); i++) {
    for(int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << "  ";
    }
    cout << endl;
  }
  return 0;
}