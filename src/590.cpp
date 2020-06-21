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
    vector<int> postorder(Node* root) {
        stack<Node*> s1;
        stack<Node*> s2;
        if (root) {
            s1.push(root);
        }

        while (!s1.empty()) {
            Node *temp = s1.top();
            s1.pop();
            s2.push(temp);
            for (int i = 0; i < temp->children.size(); ++i) {
                s1.push(temp->children[i]);
            }
        }

        vector<int> res;
        while(!s2.empty()) {
            Node *temp = s2.top();
            s2.pop();
            res.push_back(temp->val);
        }
        return res;
    }
};