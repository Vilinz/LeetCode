#include <iostream>
#include "header.h"

int guess(int num) {
  if (num == 6) {
    return 0;
  } else if (num > 6) {
    return -1;
  } else {
    return 1;
  }
}


class Solution {
public:
  int guessNumber(int n) {
    int left = 0, right = n;
    while(left <= right) {
      int middle = left + (right - left)/2;
      int temp = guess(middle);
      if (temp == 0) {
        return middle;
      } else if (temp > 0) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  cout << s.guessNumber(10) << endl;
  return 0;
}