#include <iostream>
#include <functional>
#include <numeric>
#include <climits>
#include "header.h"

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            int temp = (target - sum) / (arr.size() - i);
            if (temp <= arr[i]) {
                double x = (target * 1.0 - sum)/(arr.size() - i);
                if (x - temp > 0.5) {
                    return temp + 1;
                } else {
                    return temp;
                }
            }
            sum += arr[i];
        }
        return arr[arr.size() - 1];
    }
};

int main() {
    vector<int> v = {2,3,5};
    Solution s;
    cout << s.findBestValue(v, 10) << endl;
    return 0;
}