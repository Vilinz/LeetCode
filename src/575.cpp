#include <iostream>
#include "header.h"

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int, int> m;
        for (auto &i : candies) {
            ++m[i];
        }
        if (m.size() >= candies.size() / 2) {
            return candies.size() / 2;
        } 
        return m.size();
    }
};

int main() {
    vector<int> v = {1,1,2,3};
    Solution s;
    cout << s.distributeCandies(v) << endl;
    return 0;
}