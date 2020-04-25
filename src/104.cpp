#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxDepth(TreeNode* root) {
    if(!root) {
      return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
  cout << s.maxDepth(n0) << endl;
  return 0;
}