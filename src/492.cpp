#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> constructRectangle(int area) {
    for(int i = sqrt(area); i  > 0; --i) {
      if(area % i == 0) {
        return {area / i, i};
      }
    }
    return {};
  }
};

int main() {
  Solution s;
  vector<int> r = s.constructRectangle(4);
  for(auto &i : r) {
    cout << i << endl;
  }
  return 0;
}