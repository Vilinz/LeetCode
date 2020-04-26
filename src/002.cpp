#include <iostream>
#include "header.h"

class Solution {
public:
  int minTime(vector<int>& time, int m) {
    int sum = 0;
    for(int i = 0; i < time.size(); i++) {
      sum += time[i];
    }

    int index = 0;
    int average = sum/m;
    int result = 0;
    for(int i = 0; i < m; i++) {
      int t = 0, max = 0;
      for(;index < time.size(); index++) {
        t += time[index];
        max = time[index] > max ? time[index] : max;
        if(t >= average) {
          break;
        }
      }
      result = (t - max > result ? t - max : result);
    }
    return result;
  }
};

int main() {
  vector<int> v = {999, 999, 999};
  Solution s;
  cout << s.minTime(v, 3) << endl;
  return 0;
}