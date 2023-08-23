#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

Node* insertLevelOrder(const vector<int>& arr, Node* root, int i, int n) {
    if (i < n && arr[i] != -1) {
        Node* temp = createNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

int calculateWeightedPathLength(Node* root, int pathLength) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return pathLength * root->data;

    return calculateWeightedPathLength(root->left, pathLength + 1) +
           calculateWeightedPathLength(root->right, pathLength + 1);
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int key;
    vector<int> tree;
    while(ss >> key){
        tree.push_back(key);
    }

    Node* root = insertLevelOrder(tree, nullptr, 0, tree.size());
    cout << calculateWeightedPathLength(root, 0);
    return 0;
}
