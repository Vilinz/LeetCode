#include <iostream>
#include "header.h"

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int beg = 0, end = numbers.size() - 1;
    while(beg < end) {
      if(numbers[beg] + numbers[end] > target) {
        end--;
      } else if(numbers[beg] + numbers[end] < target) {
        beg++;
      } else {
        return vector<int>{beg + 1, end + 1};
      }
    }
    return vector<int>();
  }
};

int main() {
  Solution s;
  vector<int> v{2,7,11,15};
  vector<int> r = s.twoSum(v, 9);
  cout << r[0] << ", " << r[1] << endl;
  return 0;
}