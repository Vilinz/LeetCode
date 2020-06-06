#include <iostream>
#include "header.h"

class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    int position;
    while((position = S.find('-')) != string::npos) {
      S.erase(S.begin() + position);
    }


    int len = S.size(), count = len % K, t = len / K;
    for(int i = 0; i < t; i++) {
      if(count + i != 0 && count + i != S.size()) {
        S.insert(count + i, 1, '-');
      } else {
        --count;
      }
      count += K;
    }
    transform(S.begin(),S.end(),S.begin(),::toupper);
    return S;
  }
};

int main() {
  Solution s;
  cout << s.licenseKeyFormatting("5F3Z-2e-9-wydcb-sdbcyd", 4) << endl;
  return 0;
}