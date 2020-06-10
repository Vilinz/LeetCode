#include <iostream>
#include "header.h"

class Solution {
public:
  string convertToBase7(int num) {
    if(num == 0) {
      return "0";
    }
    string r;
    int tag = 0;
    if(num < 0) {
      num = 0 - num;
      tag = 1;
    }
    while(num) {
      r += to_string(num%7);
      num /= 7;
    }
    if(tag) {
      r += '-';
    }
    reverse(r.begin(), r.end());
    return r;
  }
};

int main() {
  Solution s;
  cout << s.convertToBase7(-100) << endl;
  return 0;
}