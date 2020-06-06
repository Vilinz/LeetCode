#include <iostream>
#include "header.h"

class Solution {
public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    int maxL = 0, hoIndex = 0;
    
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    heaters.push_back(INT_MAX);
    if(houses[0] < heaters[0]) {
      maxL = heaters[0] - houses[0];
      if(houses[houses.size() - 1] < heaters[0]) {
        return maxL;
      }
      while(houses[hoIndex] < heaters[0]) {
        ++hoIndex;
      }
    }

    for(int i = 0; i < heaters.size() && hoIndex < houses.size(); ++hoIndex) {
      while(houses[hoIndex] < heaters[i] || houses[hoIndex] > heaters[i + 1]) {
        ++i;
      }
      maxL = max(maxL, min(houses[hoIndex] - heaters[i], heaters[i + 1] - houses[hoIndex]));
    }
    return maxL;
  }
};

int main() {
  vector<int> h = {1,2,3};
  vector<int> he = {2};
  Solution s;
  cout << s.findRadius(h, he) << endl;
  return 0;
}