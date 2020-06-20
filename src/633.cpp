#include <iostream>
#include "header.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; i * i <= c; ++i) {
            double d = sqrt(c - i * i);
            if ((int)d == d) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.judgeSquareSum(5) << endl;
    return 0;
}