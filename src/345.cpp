#include <iostream>
#include "header.h"

class Solution {
public:
  bool isVowel(char c) {
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
    c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
      return true;
    }
    return false;
  }
  string reverseVowels(string s) {
    int low = 0, high = s.size() - 1;
    while(low < high) {
      while(low < high && !isVowel(s[low])) {
        low++;
      }
      while(low < high && !isVowel(s[high])) {
        high--;
      }
      if(low < high) {
        char temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
      }
    }
    return s;
  }
};

int main() {
  Solution s;
  cout << s.reverseVowels("aA") << endl;
  return 0;
}