#include "BinaryTree.h"
#include "Queue.cpp"
#include "Stack.cpp"
#include <iostream>

using namespace std;

template <class T>
bool binaryTree<T>::isEmpty() const {
    return root == NULL;
}
template <class T>
T binaryTree<T>::Root(T flag) const {
    if (root == NULL)
        return flag;
    else
        return root->data;
}

template <class T>
int binaryTree<T>::size(binaryTree<T>::Node *t) const {
    if (t == NULL) return 0;
    return 1 + size(t->left) + size(t->right);
}

template <class T>
int binaryTree<T>::height(binaryTree<T>::Node *t) const {
    if (t == NULL)
        return 0;
    else {
        int lt = height(t->left), rt = height(t->right);
        return 1 + ((lt > rt) ? lt : rt);
    }
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t) {
    if (t == NULL) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}
template <class T>
void binaryTree<T>::clear() {
    clear(root);
}

template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const {
    if (t == NULL) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}
template <class T>
void binaryTree<T>::preOrder() const {
    cout << "\n前序遍历:";
    preOrder(root);
}
// }
template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const {
    if (t == NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}
template <class T>
void binaryTree<T>::midOrder() const {
    cout << "\n中序遍历:";
    midOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const {
    if (t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}
template <class T>
void binaryTree<T>::postOrder() const {
    cout << "\n后序遍历:";
    postOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder() const {
    linkQueue<Node *> que;  // 辅助队列
    Node *tmp;
    cout << "\n层次遍历:";
    que.enQueue(root);  // 可以先判断root是否为空
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        cout << tmp->data << ' ';
        if (tmp->left) que.enQueue(tmp->left);
        if (tmp->right) que.enQueue(tmp->right);
    }
}



template <class T>
typename binaryTree<T>::Node *binaryTree<T>::find(T x, binaryTree<T>::Node *t) const {
    Node *tmp;
    if (t == NULL) return NULL;
    if (t->data == x) return t;
    if (tmp = find(x, t->left))
        return tmp;
    else
        return find(x, t->right);
}

template <class T>
void binaryTree<T>::delLeft(T x) {
    Node *tmp = find(x, root);
    if (tmp == NULL) return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x) {
    Node *tmp = find(x, root);
    if (tmp == NULL) return;
    clear(tmp->right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const {
    Node *tmp = find(x, root);
    if (tmp == NULL || tmp->left != NULL) return flag;
    return tmp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag) const {
    Node *tmp = find(x, root);
    if (tmp == NULL || tmp->right != NULL) return flag;
    return tmp->right->data;
}

template <class T>
void binaryTree<T>::createTree(T flag) {
    linkQueue<Node *> que;
    Node *tmp;
    T x, ldata, rdata;
    cout << "\nEnter node:";
    cin >> x;
    root = new Node(x);
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        cout << "\nEnter" << tmp->data
             << "'s 2 childs'(" << flag
             << "means empty node):";
        cin >> ldata >> rdata;
        if (ldata != flag)
            que.enQueue(tmp->left = new Node(ldata));
        if (rdata != flag)
            que.enQueue(tmp->right = new Node(rdata));
    }
    cout << "create completed!\n";
}

template <class T>
void printTree(const binaryTree<T> &t, T flag) {
    linkQueue<T> q;
    q.enQueue(t.root->data);
    cout << endl;
    while (!q.isEmpty()) {
        char p, l, r;
        p = q.deQueue();
        l = t.lchild(p, flag);
        r = t.rchild(p, flag);
        cout << p << " " << l << " " << r << endl;
        if (l != flag) q.enQueue(l);
        if (r != flag) q.enQueue(r);
    }
}

template <class T>
void binaryTree<T>::preOrderNonRecursive() const {
    linkStack<Node *> s;
    Node *current;
    cout << "前序遍历: ";
    s.push(root);  // root是否为NULL?
    while (!s.isEmpty()) {
        current = s.pop();
        cout << current->data;
        if (current->right != NULL) s.push(current->right);
        if (current->left != NULL) s.push(current->left);
    }
}

template <class Type>
void binaryTree<Type>::midOrderNonRecursive() const {
    linkStack<StNode> s;
    StNode current(root);  // 提前判断一下是否是空树
    cout << "中序遍历: ";
    s.push(current);
    while (!s.isEmpty()) {
        current = s.pop();
        if (++current.TimesPop == 2)  // TimesPop的变化
        {
            cout << current.node->data;
            if (current.node->right != NULL)
                s.push(StNode(current.node->right));
        } else {
            s.push(current);
            if (current.node->left != NULL)
                s.push(StNode(current.node->left));
        }
    }
}

template <class Type>
void binaryTree<Type>::postOrderNonRecursive() const {
    linkStack<StNode> s;
    StNode current(root);
    cout << "后序遍历: ";
    s.push(current);
    while (!s.isEmpty()) {
        current = s.pop();
        if (++current.TimesPop == 3) { // both childern have been visited
            cout << current.node->data;
            continue;
        }
        s.push(current);
        if (current.TimesPop == 1) {
            if (current.node->left != NULL)
                s.push(StNode(current.node->left));
        } else {
            if (current.node->right != NULL)
                s.push(StNode(current.node->right));
        }
    }
}

int main(int argc, char const *argv[]) {
    binaryTree<char> tree;
    tree.createTree('@');
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    tree.levelOrder();

    printTree(tree, '@');

    tree.delLeft ('L');
    tree.delRight('C');
    tree.delLeft ('C');
    // printTree(tree,'@');
    return 0;
}

