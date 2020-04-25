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
  vector<int> rightSideView(TreeNode* root) {
    if(!root) {
      return vector<int>();
    }
    queue<pair<TreeNode*, int>> q;
    vector<int> result;
    q.push(pair<TreeNode*,int>(root, 0));
    int lastLayer = 0;
    TreeNode *lastNode = root;
    while(!q.empty()) {
      auto [temp, val] = q.front();
      q.pop();
      if(temp->left) {
        q.push(pair<TreeNode*, int>(temp->left, val + 1));
      }
      if(temp->right) {
        q.push(pair<TreeNode*, int>(temp->right, val + 1));
      }
      if(val != lastLayer) {
        result.push_back(lastNode->val);
      }
      if(q.empty()) {
        result.push_back(temp->val);
      }
      lastLayer = val;
      lastNode = temp;
    }
    return result;
  }
};

int main() {
  Solution s;
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);
  TreeNode *n3 = new TreeNode(4);
  TreeNode *n4 = new TreeNode(5);
  n0->left = n1;
  n0->right = n2;
  n1->right = n4;
  n2->right = n3;
  vector<int> r = s.rightSideView(n0);
  for(auto a : r) {
    cout << a << endl;
  }
  return 0;
}