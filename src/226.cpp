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
  TreeNode* invertTree(TreeNode* root) {
    if(!root) {
      return nullptr;
    }
    TreeNode *n = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(n);
    return root;
  }
};

void vi(TreeNode *root) {
  if(!root) {
    return;
  }
  cout << root->val << ", ";
  vi(root->left);
  vi(root->right);
}

int main() {
  Solution s;
  TreeNode *n0 = new TreeNode(4);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(7);
  TreeNode *n3 = new TreeNode(1);
  TreeNode *n4 = new TreeNode(3);
  TreeNode *n5 = new TreeNode(6);
  TreeNode *n6 = new TreeNode(9);
  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->left = n5;
  n2->right = n6;
  vi(n0);
  cout << endl;
  n0 = s.invertTree(n0);
  vi(n0);

  return 0;
}