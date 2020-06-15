#include <iostream>
#include "header.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            f[i] = i * f[i - 1];
        }
        --k;
        for (int i = n - 1; i >= 0; --i) {
            int index = k / f[i];
            k = k % f[i];
            res.push_back(num[index]);
            num.erase(index, 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 5) << endl;
    return 0;
}