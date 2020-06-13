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
    int depth(Node *node) {
        if (!node) {
            return 0;
        }
        int maxDepth = -1;
        for (int i = 0; i < node->children.size(); ++i) {
            maxDepth = max(maxDepth, depth(node->children[i]));
        }
        return maxDepth + 1;
    }
    int maxDepth(Node* root) {
        return depth(root);
    }
};

int main() {

    return 0;
}