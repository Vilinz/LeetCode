#include <iostream>
#include "header.h"

bool isBadVersion(int version) {
  return version >= 4;
}

class Solution {
public:
  int firstBadVersion(int n) {
    if (isBadVersion(0)) {
      return 0;
    }
    int left = 0, right = n;
    while (left < right) {
      int middle = left/2 + right/2;
      if (isBadVersion(middle)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }
    return right;
  }
};

int main() {
  Solution s;
  cout << s.firstBadVersion(5) << endl;
  return 0;
}