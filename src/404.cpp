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
  void order(TreeNode *node, int &res) {
    if(node->left) {
      order(node->left, res);
      if(!node->left->left && !node->left->right) {
        res += node->left->val;
      }
    }
    if(node->right) {
      order(node->right, res);
    }
  }
  int sumOfLeftLeaves(TreeNode* root) {
    int res = 0;
    if(root)
      order(root, res);
    return res;
  }
};

int main() {
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);
  TreeNode *n3 = new TreeNode(4);
  TreeNode *n4 = new TreeNode(5);
  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n1->right = n4;
  Solution s;
  cout << s.sumOfLeftLeaves(n0) << endl;
  return 0;
}