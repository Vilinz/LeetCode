#include <iostream>
#include "header.h"

class Solution {
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2) {
    vector<int> repeatCount(n1 + 1, 0);
    vector<int> nextIndex(n1 + 1, 0);

    int index = 0, count = 0;
    for(int i = 1; i <= n1; i++) {
      for(int j = 0; j < s1.size(); j++) {
        if(s1[j] == s2[index]) {
          index++;
          if(index == s2.size()) {
            count++;
            index = 0;
          }
        }
      }
  
      repeatCount[i] = count;
      nextIndex[i] = index;
      for(int p = 0; p < i; p++) {
        if(nextIndex[p] == index) {
          int inte =  i - p;
          int repeat = (n1 - p)/inte;
          int patternCount = (repeatCount[i] - repeatCount[p]) * repeat;
          int remainCount = repeatCount[p + (n1 - p)%inte];
          return (patternCount + remainCount)/n2;
        }
      }
    }
    return repeatCount[n1]/n2;
  }
};

int main() {
  Solution s;
  cout << s.getMaxRepetitions("acb", 4, "ab", 2) << endl;
  return 0;
}