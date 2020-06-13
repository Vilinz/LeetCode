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
  int selectPath(TreeNode *root, int sum) {
    if(root == nullptr) {
      return 0;
    }
    sum -= root->val;
    return (sum == 0 ? 1 : 0) + selectPath(root->left, sum) + selectPath(root->right, sum);
  }
  int pathSum(TreeNode* root, int sum) {
    if(root == nullptr) {
      return 0;
    }
    return selectPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }
};

int main() {
  
  return 0;
}