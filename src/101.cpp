#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  bool rec(TreeNode* n1, TreeNode* n2) {
    if((!n1) && (!n2)) {
      return true;
    }
    if((!n1) || (!n2)) {
      return false;
    }
    return (n1->val == n2->val) && rec(n1->left, n2->right) && rec(n1->right, n2->left);
  }
  bool isSymmetric(TreeNode* root) {
    return rec(root, root);
  }
};

int main() {
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(3);
  TreeNode *n5 = new TreeNode(4);
  TreeNode *n6 = new TreeNode(4);
  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n1->right = n5;
  n2->left = n6;
  n2->right = n4;
  Solution s;
  cout << s.isSymmetric(n0) << endl;
  return 0;
}