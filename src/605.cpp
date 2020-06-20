#include <iostream>
#include "header.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                ++i;
                continue;
            }
            if (((i - 1 >= 0 && flowerbed[i - 1] != 1) || i == 0) && 
                ((i + 1 < flowerbed.size() && flowerbed[i + 1] != 1) || i + 1 == flowerbed.size())) {
                flowerbed[i] = 1;
                if (--n <= 0) {
                    return true;
                }
            }
        }
        return n <= 0;
    }
};

int main() {
    Solution s;
    vector<int> v = {0,0,1,0,0};
    cout << s.canPlaceFlowers(v, 1) << endl;
    return 0;
}