#include <iostream>
#include "header.h"

class Solution {
public:
  string reverseWords(string s) {
    int count = 0;
    string temp;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] != ' ') {
        temp += s[i];
      } else {
        reverse(s.begin() + i - temp.size(), s.begin() + i);
        temp = "";
      }
    }
    if(temp != "") {
      reverse(s.begin() + s.size() - temp.size(), s.begin() + s.size());
    }
    return s;
  }
};

int main() {
  Solution s;
  cout << s.reverseWords("Let's take LeetCode contest") << endl;
  return 0;
}