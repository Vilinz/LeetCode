#include <iostream>
#include "header.h"

class Solution {
public:
  int findTheLongestSubstring(string s) {
    vector<int> pos(32, -1);
    pos[0] = 0;
    int status = 0, res = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == 'a')
        status ^= 1 << 0;
      if(s[i] == 'e')
        status ^= 1 << 1;
      if(s[i] == 'i')
        status ^= 1 << 2;
      if(s[i] == 'o')
        status ^= 1 << 3;
      if(s[i] == 'u')
        status ^= 1 << 4;
      if(~pos[status]) {
        res = max(res, i + 1 - pos[status]);
      } else {
        pos[status] = i + 1;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.findTheLongestSubstring("eleetminicoworoep") << endl;
  return 0;
}