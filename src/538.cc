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
  int sum = 0;
  void postOrder1(TreeNode* root) {
    if(root) {
      postOrder1(root->left);
      postOrder1(root->right);
      cout << root->val << endl;
    }
  }
  void postOrder(TreeNode* root) {
    if(root) {
      postOrder(root->right);
      sum += root->val;
      root->val = sum;
      postOrder(root->left);
    }
  }
  TreeNode* convertBST(TreeNode* root) {
    postOrder(root);
    return root;
  }
};

int main() {
  TreeNode *n0 = new TreeNode(5);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(13);
  n0->left = n1;
  n0->right = n2;
  Solution s;
  s.postOrder1(n0);
  s.convertBST(n0);
  s.postOrder1(n0);
  return 0;
}