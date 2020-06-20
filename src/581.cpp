#include <iostream>
#include <climits>
#include "header.h"

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        int first = 0, last = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                first = i - 1;
                break;
            }
        }

        
        int t = nums[first];
        int c = first;
        while (c >= 0 && nums[c] ==t) {
            first = c;
            c--;
        }
        

        for (int j = nums.size() - 2; j >= 0; j--) {
            if (nums[j] > nums[j + 1]) {
                last = j + 1;
                break;
            }
        }

        t = nums[last];
        c = last;
        while (c < nums.size() && nums[c] == t) {
            last = c;
            c++;
        }

        cout << first << ", " << last << endl;

        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int i = first; i <= last; ++i) {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
        }

        cout << minNum << ", " << maxNum << endl;

        for (int i = first - 1; i >= 0; i--) {
            if (nums[i] <= minNum) {
                first = i + 1;
                break;
            }
            if (i == 0 && nums[i] > minNum) {
                first = 0;
            }
        }

        for (int i = last + 1; i < nums.size(); ++i) {
            if (nums[i] >= maxNum) {
                last = i - 1;
                break;
            }
            if (i == nums.size() - 1 && nums[i] <= maxNum) {
                last = nums.size() - 1;
            }
        }
        cout << first << ", " << last << endl;
        return last - first + 1;
    }
};

int main() {
    vector<int> v = {2,3,1,4,5};
    Solution s;
    cout << s.findUnsortedSubarray(v) << endl;
    return 0;
}