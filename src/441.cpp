#include <iostream>
#include "header.h"

class Solution {
public:
  int arrangeCoins(int n) {
    int left = 0, right = n;
    while(left <= right) {
      long middle = (left + right)/2;
      if(middle * (middle + 1)/2 == n) {
        return middle;
      } else if(middle * (middle + 1)/2 < n) {
        if((middle + 1) * (middle + 2)/2 > n) {
          return middle;
        } else {
          left = middle + 1;
        }
      } else {
        if((middle - 1) * middle/2 < n) {
          return middle - 1;
        }  else {
          right = middle - 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  cout << s.arrangeCoins(5) << endl;
  return 0;
}