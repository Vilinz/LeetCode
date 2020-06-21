#include <iostream>
#include <climits>
#include "header.h"

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        vector<string> res;
        int minSum = INT_MAX;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); ++i) {
            if (m.count(list2[i])) {
                int temp = i + m[list2[i]];
                if (temp == minSum) {
                    res.push_back(list2[i]);
                } else if (temp < minSum) {
                    res.clear();
                    res.push_back(list2[i]);
                    minSum = temp;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> v1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> v2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    vector<string> r = s.findRestaurant(v1, v2);
    for (auto &i : r) {
        cout << i << ",";
    }
    cout << endl;
    return 0;
}