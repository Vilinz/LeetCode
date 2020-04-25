#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) {
      return vector<vector<int>>();
    }
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    int begin = intervals[0][0], end = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++) {
      if(intervals[i][0] <= end) {
        end = max(intervals[i][1], end);
      } else {
        vector<int> t{begin, end};
        result.push_back(t);
        begin = intervals[i][0];
        end = intervals[i][1];
      }
    }
    vector<int> t{begin, end};
    result.push_back(t);
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v{{1,3}, {2,6},{8,10},{15,18}};
  vector<vector<int>> r = s.merge(v);
  for(int i = 0; i < r.size(); i++) {
    cout << "[";
    for(int j = 0; j < 2; j++) {
      cout << r[i][j] << ", ";
    }
    cout << "],";
  }
  cout << endl;
  return 0;
}