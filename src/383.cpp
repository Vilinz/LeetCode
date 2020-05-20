#include <iostream>
#include "header.h"

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int cnt[26] = {0};        
    for(int i = 0; i < magazine.length(); i++) 
      cnt[magazine[i]-'a']++;                         
    for(int i = 0; i < ransomNote.length(); i++) 
      if(--cnt[ransomNote[i]-'a'] < 0) return false;   
    return true;
  }
};

int main() {
  Solution s;
  cout << s.canConstruct("aab", "baa") << endl;
  return 0;
}