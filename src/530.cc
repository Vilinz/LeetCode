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
  void inorder(TreeNode* root, int &minDis, int &preVal) {
    if(root) {
      inorder(root->left, minDis, preVal);
      if(preVal != -1) {
        minDis = min(abs(root->val - preVal), minDis);
      }
      preVal = root->val;
      inorder(root->right, minDis, preVal);
    }
  }
  int getMinimumDifference(TreeNode* root) {
    int minDis = INT_MAX;
    TreeNode *n = root;
    int preVal = -1;
    inorder(root, minDis, preVal);
    return minDis;
  }
};

int main() {
  Solution s;
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(3);
  TreeNode *n2 = new TreeNode(2);
  n0->right = n1;
  n1->left = n2;
  cout << s.getMinimumDifference(n0) << endl;
  return 0;
}