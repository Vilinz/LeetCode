#include <iostream>
#include "header.h"

class Solution {
public:
  int countSegments(string s) {
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
      if(i - 1 > 0 && s[i - 1] != ' ' && s[i] == ' ') {
        count++;
      }
    }
    if(s.size() > 0 && s[s.size() - 1] != ' ') {
      count++;
    }
    return count;
  }
};

int main() {
  string str = "Hello, my name is John";
  Solution s;
  cout << s.countSegments(str) << endl;
  return 0;
}