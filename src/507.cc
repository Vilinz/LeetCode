#include <iostream>
#include "header.h"

class Solution {
public:
  bool checkPerfectNumber(int num) {
    int res = 1;
    for(int i = 2; i <= sqrt(num); ++i) {
      if(num % i == 0) {
        res += i;
        res += num / i;
      }
    }
    return res == num && num != 1;
  }
};

int main() {
  Solution s;
  cout << s.checkPerfectNumber(28) << endl;
  return 0;
}