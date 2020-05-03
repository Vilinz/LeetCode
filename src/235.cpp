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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *node = root;
    while(node) {
      if(p->val < node->val && q->val < node->val) {
        node = node->left;
      } else if(p->val > node->val && q->val > node->val) {
        node = node->right;
      } else {
        return node;
      }
    }
    return nullptr;
  }
};

int main() {
  TreeNode *n0 = new TreeNode(6);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(8);
  n0->left = n1;
  n0->right = n2;
  Solution s;
  TreeNode *r = s.lowestCommonAncestor(n0, n1, n2);
  cout << r->val << endl;
  return 0;
}