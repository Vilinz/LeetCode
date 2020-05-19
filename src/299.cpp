#include <iostream>
#include "header.h"

class Solution {
public:
  string getHint(string secret, string guess) {
    map<char, int> m, m1;
    int total = 0, ACount = 0;
    for(int i = 0; i < secret.size(); i++) {
      m[secret[i]]++;
      m1[guess[i]]++;
      if(secret[i] == guess[i]) {
        ACount++;
      }
    }
    for(auto it = m1.begin(); it != m1.end(); it++) {
      auto temp = m.find(it->first);
      if(temp != m.end()) {
        total += min(it->second, temp->second);
      }
    }
    return to_string(ACount) + "A" + to_string(total - ACount) + "B";
  }
};

int main() {
  Solution s;
  cout << s.getHint("1123", "0111") << endl;
  return 0;
}