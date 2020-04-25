#include <iostream>
#include "header.h"

class Solution {
public:
  string convertToTitle(int n) {
    string r;
    while(n > 0) {
      n--;
      r += 'A' + n%26;
      n = n/26;
    }
    reverse(r.begin(), r.end());
    return r;
  }
};

int main() {
  Solution s;
  cout << s.convertToTitle(53) << endl;
  return 0;
}