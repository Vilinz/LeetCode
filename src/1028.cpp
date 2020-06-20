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
    int index = 0;
    TreeNode* dfs(string s, int depth) {
        if (index >= s.size()) {
            return nullptr;
        }
        int temp = 0;
        for (int i = index; i < s.size(); ++i) {
            if (s[i] != '-') {
                break;
            } else {
                ++temp;
            }
        }

        if (temp != depth) {
            return nullptr;
        } else {
            index += temp;
        }

        int num = 0;
        for (int i = index; i < s.size(); ++i) {
            if (s[i] == '-') {
                break;
            } else {
                num = num * 10 + s[i] - '0';
                index++;
            }
        }

        TreeNode* newNode = new TreeNode(num);
        newNode->left = dfs(s, depth + 1);
        newNode->right = dfs(s, depth + 1);
        return newNode;
        
    }
    TreeNode* recoverFromPreorder(string S) {
        int depth = 0;
        TreeNode *res = dfs(S, depth);
        return res;
    }
};


void preorder(TreeNode *node) {
    if (!node) {
        return;
    }
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode *temp = q.front();
        cout << temp->val << ", ";
        q.pop();
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
}

int main() {
    Solution s;
    TreeNode *n = s.recoverFromPreorder("1-2--3--4-5--6--7");
    preorder(n);
    return 0;
}