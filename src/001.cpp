#include <iostream>
#include "header.h"

class Solution {
public:
  int expectNumber(vector<int>& scores) {
    vector<int> same;
    int count = 1;
    for(int i = 1; i < scores.size(); i++) {
      if(scores[i] == scores[i - 1]) {
        count++;
      } else {
        if(count >= 2) {
          same.push_back(count);
          count = 1;
        }
      }
    }
    if(count >= 2) {
      same.push_back(count);
    }

    int total = 1;
    for(int i = 0; i < same.size(); i++) {
      total *= pow(2, same[i]);
    }

    

    for(auto a : same) {
      cout << a << endl;
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> v = {1,1,1,2,3,4,4,4,5,5};
  cout << s.expectNumber(v) << endl;
  return 0;
}