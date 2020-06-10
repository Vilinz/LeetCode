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
  int maxL = 1;
  int dep(TreeNode* node) {
    if(!node) {
      return 0;
    }
    int l = dep(node->left);
    int r = dep(node->right);
    maxL = max(maxL, l + r + 1);
    return max(l, r) + 1;
  }
  int diameterOfBinaryTree(TreeNode* root) {
    dep(root);
    return maxL - 1;
  }
};

int main() {

  return 0;
}