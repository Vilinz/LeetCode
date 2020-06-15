#include <iostream>
#include "header.h"

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLength = 0;
        map<int, int> m;
        for (auto &i : nums) {
            ++m[i];
        }

        for (auto it = ++m.begin(); it != m.end(); ++it) {
            auto temp = it--;
            if (temp == m.end()) {
                return maxLength;
            }
            if (temp->first == it->first + 1) {
                maxLength = max(maxLength, temp->second + it->second);
            }
            it = temp;
        }
        return maxLength;
    }
};

int main() {
    vector<int> v = {1,3,2,2,5,2,3,7};
    Solution s;
    cout << s.findLHS(v) << endl;
    return 0;
}