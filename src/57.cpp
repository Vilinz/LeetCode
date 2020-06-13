#include <iostream>
#include "header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
        }
        int left = 0, right = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(intervals[i]);
            } else {
                if ((newInterval[0] < intervals[i][0] && newInterval[1] >= intervals[i][0]) || 
                    (intervals[i][0] >= newInterval[0])) {
                    left = newInterval[0];
                } else {
                    left = intervals[i][0];
                }
                int flag = 0;
                while (i < intervals.size() && (intervals[i][1] <= newInterval[1] || intervals[i][0] <= newInterval[1])) {
                    ++i;
                    flag = 1;
                }

                if (flag == 1) {
                    --i;
                }
                if ((newInterval[1] >= intervals[i][1])) {
                    right = newInterval[1];
                } else {
                    right = intervals[i][1];
                }

                res.push_back({left, right});
            }
            if (i + 1 < intervals.size() && intervals[i][1] < newInterval[0] && intervals[i+1][0] > newInterval[1]) {
                res.push_back(newInterval);
            }
        }

        if (!res.empty() && res[res.size() - 1][1] < newInterval[0]) {
            res.push_back(newInterval);
        }

        if (!res.empty() && newInterval[1] < res[0][0]) {
            res.insert(res.begin(), newInterval);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> v = {{3,5},{12,15}};
    vector<int> newV = {6,6};
    Solution s;
    vector<vector<int>> r = s.insert(v, newV);
    for (auto &i : r) {
        for (auto &j : i) {
            cout << j << ", ";
        }
        cout << endl;
    }
    return 0;
}