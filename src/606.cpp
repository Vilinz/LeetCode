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
    string tree2str(TreeNode* t) {
        if (!t) {
            return "";
        }
        if (t->left == nullptr && t->right == nullptr) {
            return to_string(t->val) + "";
        }
        if (t->right == nullptr) {
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        }
        return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};

int main() {
    Solution s;
    TreeNode *n0 = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    cout << s.tree2str(n0) << endl;
    return 0;
}