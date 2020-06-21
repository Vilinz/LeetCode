#include <iostream>
#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<int, TreeNode*>> q;
        vector<double> res;
        int currLayer = 0, count = 0;
        double sum = 0.0;
        if (!root) {
            return {};
        }
        q.push(pair<int, TreeNode*>(0, root));

        while (!q.empty()) {
            auto [layer, temp] = q.front();
            q.pop();
            if (layer != currLayer) {
                res.push_back(sum/count);
                count = 1;
                sum = temp->val;
                currLayer = layer;
            } else {
                sum += temp->val;
                ++count;
            }
            if (temp->left) {
                q.push(pair<int, TreeNode*>(layer + 1, temp->left));
            }
            if (temp->right) {
                q.push(pair<int, TreeNode*>(layer + 1, temp->right));
            }
        }
        if (count != 0) {
            res.push_back(sum/count);
        }
        return res;
    }
};

int main() {
    Solution s;
    TreeNode *n0 = new TreeNode(3);
    TreeNode *n1 = new TreeNode(9);
    TreeNode *n2 = new TreeNode(20);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(7);
    n0->left = n1;
    n0->right = n2;
    n2->left = n3;
    n2->right = n4;
    vector<double> r = s.averageOfLevels(n0);
    for (auto &i : r) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}