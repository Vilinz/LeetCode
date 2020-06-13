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
    int total = 0;
    int diff(TreeNode *node) {
        if (!node) {
            return 0;
        }
        int left = diff(node->left);
        int right = diff(node->right);
        total += abs(left - right);
        return node->val + left + right;
    }
    int findTilt(TreeNode* root) {
        diff(root);
        return total;
    }
};

int main() {
    TreeNode *n0 = new TreeNode(1); 
    TreeNode *n1 = new TreeNode(2); 
    TreeNode *n2 = new TreeNode(3); 
    n0->left = n1;
    n0->right = n2;
    Solution s;
    cout << s.findTilt(n0) << endl;
    return 0;
}