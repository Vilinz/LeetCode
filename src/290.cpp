#include <iostream>
#include "header.h"

class Solution {
public:
  bool wordPattern(string pattern, string str) {
    map<char, string> m1;
    map<string, char> m2;
    vector<string> strV;
    string t;
    for(int i = 0; i < str.size(); i++) {
      if(str[i] == ' ') {
        strV.push_back(t);
        t = "";
      } else {
        t += str[i];
      }
    }
    strV.push_back(t);
    if(strV.size() != pattern.size()) {
      return false;
    }
    for(int i = 0; i < pattern.size(); i++) {
      if (m1.find(pattern[i]) != m1.end()) {
        if (m1[pattern[i]] != strV[i]) {
          return false;
        }
      } else if (m2.find(strV[i]) != m2.end()) {
        if (m2[strV[i]] != pattern[i]) {
          return false;
        }
      } else {
        m1[pattern[i]] = strV[i];
        m2[strV[i]] = pattern[i];
      }

    }
    return true;
  }
};

int main() {
  Solution s;
  string pattern = "abba", str = "dog cat cat dog";
  cout << s.wordPattern(pattern, str) << endl;
  return 0;
}