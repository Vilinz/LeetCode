#include <iostream>
#include <unordered_set>
#include "header.h"

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while(n != 1 && ! s.count(n)) {
      s.insert(n);
      int next = 0;
      while(n) {
        next += (n%10)*(n%10);
        n /= 10;
      }
      n = next;
    }
    return n == 1;
  }
};

int main() {
  Solution s;
  cout << s.isHappy(2) << endl;
  return 0;
}