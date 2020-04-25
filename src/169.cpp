#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    map<int, int> result;
    if(nums.size() == 1) {
        return nums[0];
    }
    for(int i = 0; i < nums.size(); i++) {
      if(result.find(nums[i]) == result.end()) {
        result[nums[i]] = 1;
      } else {
        result[nums[i]]++;
        if(result[nums[i]] > (nums.size() / 2)) {
          return nums[i];
        }
      }
    }
    return 0;
  }
};

int main() {
  vector<int> a{3,2,3};
  Solution s;
  cout << s.majorityElement(a) << endl;
  return 0;
}