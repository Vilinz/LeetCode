#include <iostream>
#include "header.h"

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int time = 0;
    for(int i = 0; time < nums.size(); i++) {
      int pre = nums[i], current = i;
      while(true) {
        int next = (k + current)%nums.size();
        int temp = nums[next];
        nums[next] = pre;
        pre = temp;
        current = next;
        time++;
        if(current == i) {
          break;
        }
      }
    }
  }
};

int main() {
  vector<int> v = {1,2,3,4,5,6,7};
  Solution s;
  s.rotate(v, 3);
  for(auto a : v) {
    cout << a << ", ";
  }
  cout << endl;
  return 0;
}