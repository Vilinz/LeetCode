#include <iostream>
#include <vector>
#include <queue>
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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    queue<pair<int, TreeNode*>> q;
    if(root) {
      q.emplace(1, root);
    }

    while(!q.empty()) {
      auto [layer, temp] = q.front();
      q.pop();
      if(result.size() < layer) {
        vector<int> t{temp->val};
        result.push_back(t);
      } else {
        result[layer - 1].push_back(temp->val);
      }
      if(temp->left) {
        q.emplace(layer + 1, temp->left);
      }
      if(temp->right) {
        q.emplace(layer + 1, temp->right);
      }
    }
    reverse(result.begin(), result.end());

    return result;
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
  vector<vector<int>> v = s.levelOrderBottom(n0);
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}