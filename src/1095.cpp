#include <iostream>
#include "header.h"

class MountainArray {
public:
  int get(int index) {
    return num[index];
  }
  int length() {
    return num.size();
  }
private:
  vector<int> num = {1,2,3,4,5,3,1};
};


class Solution {
public:
  int findMax(MountainArray &mountainArr) {
    int l = 0, r = mountainArr.length() - 1;
    while(l < r) {
      int middle = (l + r)/2;
      if(mountainArr.get(middle) < mountainArr.get(middle + 1)) {
        l = middle + 1;
      } else {
        r = middle;
      }
    }
    return l;
  }

  int findInLeft(int target, int l, int r, MountainArray &mountainArr) {
    while (l <= r) {
      int middle = (l + r)/2;
      int midNum = mountainArr.get(middle);
      if (midNum == target) {
        return middle;
      } else if (midNum > target) {
        r = middle - 1;
      } else {
        l = middle + 1;
      }
    }
    return -1;
  }

  int findInRight(int target, int l, int r, MountainArray &mountainArr) {
    while (l <= r) {
      int middle = (l + r)/2;
      int midNum = mountainArr.get(middle);
      if (midNum == target) {
        return middle;
      } else if (midNum > target) {
        l = middle + 1;
      } else {
        r = middle - 1;
      }
    }
    return -1;
  }

  int findInMountainArray(int target, MountainArray &mountainArr) {
    int len = mountainArr.length() - 1;
    int maxIndex = findMax(mountainArr);
    int l = findInLeft(target, 0, maxIndex, mountainArr);
    if(l != -1) {
      return l;
    }
    int r = findInRight(target, maxIndex, len, mountainArr);
    return r;
    
  }
};

int main() {
  Solution s;
  MountainArray arr;
  cout << s.findInMountainArray(2, arr) << endl;
  return 0;
}