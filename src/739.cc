#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size());
    stack<int> s;

    for(int i = 0; i < T.size(); ++i) {
      if(s.empty()) {
        s.push(i);
      } else {
        if(T[i] > T[s.top()]) {
          while(!s.empty() && T[i] > T[s.top()]) {
            res[s.top()] = i - s.top();
            s.pop();
          }
          s.push(i);
        } else {
          s.push(i);
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
  Solution s;
  vector<int> r = s.dailyTemperatures(v);
  for(auto &i : r) {
    cout << i << ",";
  }
  cout << endl;
  return 0;
}