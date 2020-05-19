#include <iostream>
#include "header.h"

class Solution {
public:
  void reverseString(vector<char>& s) {
    int low = 0, high = s.size() - 1;
    while(low < high) {
      char temp = s[low];
      s[low] = s[high];
      s[high] = temp;
      low++;
      high--;
    }
  }
};

int main() {
  vector<char> v = {'h','e','l','l','o'};
  Solution s;
  s.reverseString(v);
  for(auto a : v) {
    cout << a << ", ";
  }
  cout << endl;
  return 0;
}