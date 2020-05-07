#include <iostream>
#include "header.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == nullptr) return false;
    if (dfs(s, t)) return true;
    return (isSubtree(s->left, t) || isSubtree(s->right, t));
  }

  bool dfs(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) return true;
    if (s == nullptr || t == nullptr) return false;
    if (s->val != t->val) return false;
    return (dfs(s->left, t->left) && dfs(s->right, t->right));
  }
};

int main() {
  TreeNode *n0 = new TreeNode(3);
  TreeNode *n1 = new TreeNode(4);
  TreeNode *n2 = new TreeNode(5);
  TreeNode *n3 = new TreeNode(1);
  TreeNode *n4 = new TreeNode(2);
  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n1->right = n4;

  TreeNode *n5 = new TreeNode(4);
  TreeNode *n6 = new TreeNode(1);
  TreeNode *n7 = new TreeNode(2);
  n5->left = n6;
  n5->right = n7;

  Solution s;
  cout << s.isSubtree(n0, n5) << endl;
  return 0;
}