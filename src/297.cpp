#include <iostream>
#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfs(root, "");
    }

    string dfs(TreeNode* root, string str) {
        if (!root) {
            return str + "!,";
        }
        str += to_string(root->val) + ",";
        str = dfs(root->left, str);
        str = dfs(root->right, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return recover(data, i);
    }

    TreeNode* recover(string& q, int& u) {
        if (q[u] == '!') {
            u += 2;
            return nullptr;
        }
        if (q.empty() || u >= q.size()) {
            return nullptr;
        }
        int index = 0;
        string temp;
        for (int i = u; i < q.size(); ++i) {
            if (q[i] == ',') {
                index = i;
                break;
            } else {
                temp += q[i];
            }
        }
        u = index + 1;
        TreeNode *root = new TreeNode(stoi(temp.c_str()));
        root->left = recover(q, u);
        root->right = recover(q, u);
        return move(root);
    }
};

int main() {
    TreeNode *n0 = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    n0->left = n1;
    n0->right = n2;
    n2->left = n3;
    n2->right = n4;
    Codec c;
    string t = c.serialize(n0);
    cout << t << endl;
    TreeNode* n = c.deserialize(t);
    cout << c.serialize(n) << endl;
    return 0;
}