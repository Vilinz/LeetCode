#include <iostream>
#include <climits>
#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        res = max(res, max(node->val, node->val + left));
        res = max(res, max(node->val + right, node->val + left + right));
        res = max(node->val, max(res, node->val + left + right));
        return max(max(left, right) + node->val, node->val);
    }
};

int main() {
    TreeNode *n0 = new TreeNode(1);
    TreeNode *n1 = new TreeNode(-3);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(7);
    n0->left = n1;
    n0->right = n2;
    /*
    n2->left = n3;
    n2->right = n4;
    */
    Solution s;
    cout << s.maxPathSum(n0) << endl;
    return 0;
}