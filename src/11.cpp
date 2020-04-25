#include <iostream>
#include "header.h"

class Solution {
public:
  int maxArea(vector<int>& height) {
    int maxNum = 0;
    int beg = 0, end = height.size() - 1;
    while(beg < end) {
      maxNum = max(maxNum, min(height[beg], height[end]) * (end - beg));
      cout << maxNum << endl;
      if(height[beg] > height[end]) {
        end--;
      } else {
        beg++;
      }
    }
    return maxNum;
  }
};

int main() {
  Solution s;
  vector<int> v{1,8,6,2,5,4,8,3,7};
  cout << s.maxArea(v) << endl;
  return 0;
}