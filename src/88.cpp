#include <iostream>
#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, currIndex = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            nums1[currIndex--] = nums1[p1] > nums2[p2] ? nums1[p1--] : nums2[p2--];
        }
        while (p2 >= 0) {
            nums1[currIndex--] = nums2[p2--];
        }
    }
};

int main() {
    vector<int> v1 = {4,5,6,0,0,0}, v2 = {1,2,3};
    Solution s;
    s.merge(v1, 3, v2, 3);
    for (auto &i : v1) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}