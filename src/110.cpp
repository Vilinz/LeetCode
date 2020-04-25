#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int rec(TreeNode *node) {
    if(!node) {
      return 0;
    }
    return max(rec(node->left), rec(node->right)) + 1;
  }
  bool isBalanced(TreeNode* root) {
    if(!root) {
      return true;
    }
    if(abs(rec(root->left) - rec(root->right)) > 1) {
      return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
  }
};

int main() {
  Solution s;
  TreeNode *n0 = new TreeNode(3);
  TreeNode *n1 = new TreeNode(9);
  TreeNode *n2 = new TreeNode(20);
  TreeNode *n3 = new TreeNode(15);
  TreeNode *n4 = new TreeNode(7);
  n0->left = n1;
  n0->right = n2;
  n2->left = n3;
  n2->right = n4;
  cout << s.isBalanced(n0) << endl;
  return 0;
}