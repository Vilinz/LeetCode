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
  void inorder(TreeNode *node, int &pre, int &maxCount, int &currentCount, vector<int> &r) {
    if(node) {
      inorder(node->left, pre, maxCount, currentCount, r);
      if(node->val == pre) {
        ++currentCount;
      } else {
        if(currentCount == maxCount) {
          r.push_back(pre);
        } else if(currentCount > maxCount) {
          maxCount = currentCount;
          r.clear();
          r.push_back(pre);
        }
        currentCount = 1;
      }
      pre = node->val;
      inorder(node->right, pre, maxCount, currentCount, r);
    }
  }
  vector<int> findMode(TreeNode* root) {
    if(!root) {
      return {};
    }
    vector<int> r;
    int maxCount = 0, currentCount = 0, pre;
    TreeNode *temp = root;
    while(temp->left) {
      temp = temp->left;
    }
    pre = temp->val;
    inorder(root, pre, maxCount, currentCount, r);
    if(currentCount == maxCount) {
      r.push_back(pre);
    } else if(currentCount > maxCount) {
      maxCount = currentCount;
      r.clear();
      r.push_back(pre);
    }
    return r;
  }
};

int main() {
  Solution s;
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(2);
  n0->right = n1;
  n1->left = n2;
  vector<int> v = s.findMode(n0);
  for(auto &i : v) {
    cout << i << endl;
  }
  return 0;
}