#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    long long searchLength;
    long long numNodes;
};

Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    node->height = 1;
    node->searchLength = 1;
    node->numNodes = 1;
    return node;
}

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

long long getNumNodes(Node* node) {
    if (node == nullptr)
        return 0;
    return node->numNodes;
}

long long getSearchLength(Node* node) {
    if (node == nullptr)
        return 0;
    return node->searchLength;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    y->left = T2;
    x->right = y;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->numNodes = getNumNodes(y->left) + getNumNodes(y->right) + 1;
    x->numNodes = getNumNodes(x->left) + getNumNodes(x->right) + 1;
    y->searchLength = getSearchLength(y->left) + getSearchLength(y->right) + getNumNodes(y);
    x->searchLength = getSearchLength(x->left) + getSearchLength(x->right) + getNumNodes(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->numNodes = getNumNodes(x->left) + getNumNodes(x->right) + 1;
    y->numNodes = getNumNodes(y->left) + getNumNodes(y->right) + 1;
    x->searchLength = getSearchLength(x->left) + getSearchLength(x->right) + getNumNodes(x);
    y->searchLength = getSearchLength(y->left) + getSearchLength(y->right) + getNumNodes(y);
    return y;
}

int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    node->numNodes = getNumNodes(node->left) + getNumNodes(node->right) + 1;
    node->searchLength = getSearchLength(node->left) + getSearchLength(node->right) + getNumNodes(node);

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() {
    Node* root = nullptr;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int key;
    while (ss >> key) {
        root = insert(root, key);
    }
    cout << root->searchLength / root->numNodes;
    return 0;
}
