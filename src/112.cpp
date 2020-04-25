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
  bool hasPathSum(TreeNode* root, int sum) {
    if(!root) {
      return false;
    }
    sum -= root->val;
    if((!root->left) && (!root->right)) {
      return (sum == 0);
    }
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
  }
};

int main() {
  TreeNode *n0 = new TreeNode(5);
  TreeNode *n1 = new TreeNode(4);
  TreeNode *n2 = new TreeNode(8);
  TreeNode *n3 = new TreeNode(11);
  TreeNode *n4 = new TreeNode(13);
  TreeNode *n5 = new TreeNode(4);
  TreeNode *n6 = new TreeNode(7);
  TreeNode *n7 = new TreeNode(2);
  TreeNode *n8 = new TreeNode(1);
  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n3->left = n6;
  n3->right = n7;
  n2->right = n4;
  n2->right = n5;
  n5->right = n8;
  Solution s;
  cout << s.hasPathSum(n0, 22) << endl;
  return 0;
}