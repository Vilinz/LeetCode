#include <iostream>
#include "header.h"

class Solution {
public:
  bool isPerfectSquare(int num) {
    int left = 0, right = num;
    if(num ==0 || num == 1) {
      return true;
    }
    while (left <= right) {
      int middle = (left + right)/2;
      if ((double)num/middle - middle == 0) {
        return true;
      } else if ((double)num/middle - middle > 0) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  cout << s.isPerfectSquare(5) << endl;
  return 0;
}