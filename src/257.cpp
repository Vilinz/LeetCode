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
  void search(TreeNode* node, string cur, vector<string> &result) {
    if(node == nullptr) {
      return;
    }
    if(node->left == nullptr && node->right == nullptr) {
      cur = cur + to_string(node->val);
      result.push_back(cur);
      return;
    }

    cur = cur + to_string(node->val) + "->";
    search(node->left, cur, result);
    search(node->right, cur, result);
  }
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    search(root, "", result);
    return result;
  }
};

int main() {
  Solution s;
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);
  TreeNode *n3 = new TreeNode(5);
  n0->left = n1;
  n0->right = n2;
  n1->right = n3;
  vector<string> r = s.binaryTreePaths(n0);
  for(auto a : r) {
    cout << a << endl;
  }
  return 0;
}