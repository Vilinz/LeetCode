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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) {
            return t2;
        }
        if (!t2) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

void pre(TreeNode *node) {
    if (!node) {
        return;
    }
    cout << node->val << ", ";
    pre(node->left);
    pre(node->right);
}

int main() {
    TreeNode *n0 = new TreeNode(1);
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(5);
    n0->left = n1;
    n1->left = n3;
    n0->right = n2;

    TreeNode *n4 = new TreeNode(2);
    TreeNode *n5 = new TreeNode(1);
    TreeNode *n6 = new TreeNode(3);
    TreeNode *n7 = new TreeNode(4);
    TreeNode *n8 = new TreeNode(7);
    n4->left = n5;
    n5->right = n7;
    n4->right = n6;
    n6->right = n8;

    Solution s;
    TreeNode *res = s.mergeTrees(n0, n4);
    pre(res);
    return 0;
}