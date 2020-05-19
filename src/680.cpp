#include <iostream>
#include "header.h"

class Solution {
public:
  bool isPalinDrome(string s, int low, int height) {
    while(low < height) {
      if(s[low] != s[height]) {
        return false;
      }
      low++;
      height--;
    }
    return true;
  }
  bool validPalindrome(string s) {
    int low = 0, height = s.size() - 1;
    while(low < height) {
      if(s[low] == s[height]) {
        low++;
        height--;
      } else {
        return isPalinDrome(s, low + 1, height) || isPalinDrome(s, low, height - 1);
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.validPalindrome("abcda") << endl;
  return 0;
}