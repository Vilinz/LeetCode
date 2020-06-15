#include <iostream>
#include "header.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
/*
    void pre(Node* node, vector<int> &res) {
        if (!node) {
            return;
        }
        res.push_back(node->val);
        for (int i = 0; i < node->children.size(); ++i) {
            pre(node->children[i], res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        pre(root, res);
        return res;
    }
*/
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> q;
        if (root) {
            q.push(root);
        }
        while(!q.empty()) {
            Node *temp = q.top();
            q.pop();
            res.push_back(temp->val);
            for (int i = temp->children.size(); i >= 0; --i) {
                q.push(temp->children[i]);
            }
        }
        return res;
    }
};

int main() {

    return 0;
}