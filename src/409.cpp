#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    map<char, int> mapping;
    int count = 0, tag = 0;
    for(int i = 0; i < s.size(); i++) {
      mapping[s[i]]++;
    }

    for(auto it : mapping) {
      if(it.second % 2 == 0) {
        count += it.second;
      } else {
        count += it.second - 1;
        tag = 1;
      }
    }
    if(tag == 1) {
      count += 1;
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("abccccdd") << endl;
  return 0;
}