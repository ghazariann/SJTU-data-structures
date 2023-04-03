#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int widthOfBinaryTree(Node* root) {
    if (!root) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int maxWidth = 1;
    while (!q.empty()) {
        int width = q.size();
        maxWidth = max(maxWidth, width);
        for (int i = 0; i < width; i++) {
            Node* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    return maxWidth;
}