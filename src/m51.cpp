#include <iostream>
#include "header.h"

class Solution {
public:
  int count = 0;
  void mergeSort(vector<int>& nums, vector<int>& temp, int l, int r) {
    if(l >= r) {
      return;
    }
    int middle = (l + r) / 2;
    mergeSort(nums, temp, l, middle);
    mergeSort(nums, temp, middle + 1, r);
    int i = l, j = middle + 1, k = l;
    while(i <= middle && j <= r) {
      if(nums[j] < nums[i]) {
        temp[k++] = nums[j++];
        count += (middle - i + 1);
      } else {
        temp[k++] = nums[i++];
      }
    }
    if(i <= middle) {
      copy(nums.begin() + i, nums.begin() + middle + 1, temp.begin() + k);
    }
    if(j <= r) {
      copy(nums.begin() + j, nums.begin() + r + 1, temp.begin() + k);
    }
    copy(temp.begin() + l, temp.begin() + r + 1, nums.begin() + l);
  }
  int reversePairs(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    vector<int> temp(r + 1, 0);
    mergeSort(nums, temp, l, r);
    return count;
  }
};

int main() {
  Solution s;
  vector<int> v={7,5,6,4};
  cout << s.reversePairs(v) << endl;
  return 0;
}