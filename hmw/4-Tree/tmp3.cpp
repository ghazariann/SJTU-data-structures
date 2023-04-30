#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int weight;
    char symbol;
    Node* left;
    Node* right;
    Node(int weight, char symbol = '\0', Node* left = nullptr, Node* right = nullptr) : weight(weight), symbol(symbol), left(left), right(right) {}
};

bool compare(Node* a, Node* b) {
    return a->weight > b->weight;
}

Node* buildHuffmanTree(vector<int> weights) {
    priority_queue<Node*, vector<Node*>, decltype(&compare)> pq(compare);
    for (int i = 0; i < weights.size(); i++) {
        pq.push(new Node(weights[i], char(i + 'A')));
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node(left->weight + right->weight, '\0', left, right);
        pq.push(parent);
    }
    return pq.top();
}

void calculateWPL(Node* root, int depth, int& wpl) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        wpl += root->weight * depth;
    }
    calculateWPL(root->left, depth + 1, wpl);
    calculateWPL(root->right, depth + 1, wpl);
}

int main() {
    vector<int> weights{15, 03, 14, 02, 06};
    Node* root = buildHuffmanTree(weights);
    int wpl = 0;
    calculateWPL(root, 0, wpl);
    cout << "Weighted Path Length: " << wpl << endl;
    return 0;
}