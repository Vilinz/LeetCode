#include <iostream>
#include "header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }

        int slowPointer = 1, count = 1;
        for (int fastPointer = 1; fastPointer < nums.size(); ++fastPointer) {
            if (nums[fastPointer] == nums[fastPointer - 1]) {
                ++count;
            } else {
                count = 1;
            }

            if (count <= 2) {
                nums[slowPointer++] = nums[fastPointer];
            }
        }
        return slowPointer;
    }
};

int main() {
    vector<int> v = {1,1,1,2,2,2,3};
    Solution s;
    cout << s.removeDuplicates(v) << endl;
    for (auto &i : v) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}