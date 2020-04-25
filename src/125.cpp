#include <iostream>
#include <cctype>
#include "header.h"

class Solution {
public:
  string cleanStr(string s) {
    string result;
    for(auto c : s) {
      if(isalnum(c)) {
        if(isalpha(c) && isupper(c)) {
          result.push_back(tolower(c));
        } else {
          result.push_back(c);
        }
      }
    }
    return result;
  }
  bool isPalindrome(string s) {
    string temp = cleanStr(s);
    int beg = 0, end = temp.size() - 1;
    while(beg < end) {
      if(temp[beg] == temp[end]) {
        beg++;
        end--;
      } else {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome("race a car") << endl;
  return 0;
}