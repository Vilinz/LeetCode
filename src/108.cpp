#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
  TreeNode* newNode(int l, int r, vector<int> &nums) {
    if(l > r) {
      return nullptr;
    }
    int mid = (l + r)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = newNode(l, mid - 1, nums);
    root->right = newNode(mid + 1, r, nums);
    return root;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return newNode(0, nums.size() - 1, nums);
  }
};

int main() {
  Solution s;
  vector<int> v{-10, -3, 0, 5, 9};
  TreeNode *n = s.sortedArrayToBST(v);
  cout << n->left->val << endl;
  return 0;
}