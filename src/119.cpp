#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1);
    for(int i = 0; i <= rowIndex; i++) {
      result[0] = 1;
      for(int j = i; j > 0; j--) {
        result[j] += result[j - 1];
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> r = s.getRow(4);
  for(auto a : r) {
    cout << a << endl;
  }
  return 0;
}