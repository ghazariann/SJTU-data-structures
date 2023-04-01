#include <iostream>

#include "Tree.h"
using namespace std;

template <class T>
class binaryTree : public bTree<T> {
    friend void printTree(const binaryTree &t, T flag);

   private:
    struct Node {
        Node *left, *right;
        T data;
        Node() : left(NULL), right(NULL) {}
        Node(T item, Node *L = NULL, Node *R = NULL) : data(item), left(L), right(R) {}
        ~Node() {}
    };
    Node *root;
    struct StNode {
        Node *node;
        int TimesPop;
        StNode(Node *N = NULL) : node(N), TimesPop(0){}  // TimesPop初始赋值0
    };

    public : binaryTree() : root(NULL) {
    }
    binaryTree(T x) { root = new Node(x); }
    ~binaryTree();
    void clear();  // 删除整棵树
    int size(Node *t) const;
    int height(Node *t) const;
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;  // 遍历整棵二叉树 （包裹函数，下同）
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);  // 输入一颗二叉树
    T parent(T x, T flag) const { return flag; }

   private:
    Node *find(T x, Node *t) const;
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;
};