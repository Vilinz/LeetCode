#include <iostream>
#include "header.h"

class Solution {
public:
  string addStrings(string num1, string num2) {
    if(num1.size() > num2.size()) {
      return addStrings(num2, num1);
    }
    int carry = 0;
    string res;
    int size1 = num1.size(), size2 = num2.size();
    for(int i = 0; i < size1; i++) {
      int temp = (num1[size1 - 1 - i] - '0') + (num2[size2 - 1 - i] - '0') + carry;
      if(temp >= 10) {
        res += to_string(temp % 10);
        carry = 1;
      } else {
        res += to_string(temp);
        carry = 0;
      }
    }
    for(int i = size2 - size1 - 1; i >= 0; i--) {
      int temp = num2[i] - '0' + carry;
      if(temp >= 10) {
        res += to_string(temp % 10);
        carry = 1;
      } else {
        res += to_string(temp);
        carry = 0;
      }
    }
    if(carry) {
      res += "1";
    }
    reverse(res.begin(), res.end());
    return res;

  }
};

int main() {
  Solution s;
  cout << s.addStrings("1", "9") << endl;
  return 0;
}