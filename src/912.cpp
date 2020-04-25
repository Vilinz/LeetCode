#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    sort(0, nums.size() - 1, nums);
    return nums;
  }

  void sort(int start, int end, vector<int>& nums) {
    if(start < end) {
      int flag = nums[start];
      int i = end, j = start;
      while(j < i) {
        while(nums[i] >= flag && j < i) {
          i--;
        }
        if(j < i) {
          nums[j++] = nums[i];
        }
        while(nums[j] <= flag && j < i) {
          j++;
        }
        if(j < i) {
          nums[i--] = nums[j];
        }
      }
      nums[j] = flag;
      sort(start, j - 1, nums);
      sort(j + 1, end, nums);
    }
  }
};

int main() {
  vector<int> a{5,2,3,1};
  Solution s;
  vector<int> re = s.sortArray(a);
  for(auto a : re) {
    cout << a << endl;
  }
  return 0;
}