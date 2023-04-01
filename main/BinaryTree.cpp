#include "BinaryTree.h"
#include "Stack.h"
#include <iostream>

#include "Queue.h"
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
    t = NULL;  // 起什么作用？
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
// template <class T>
// void binaryTree<T>::preOrder() const {
//     cout << "\n前序遍历:";
//     preOrder(root);
// }
template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const {
    if (t == NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}
// template <class T>
// void binaryTree<T>::midOrder() const {
//     cout << "\n中序遍历:";
//     midOrder(root);
// }

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const {
    if (t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}
// template <class T>
// void binaryTree<T>::postOrder() const {
//     cout << "\n后序遍历:";
//     postOrder(root);
// }

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
void binaryTree<T>::createTree(T flag) {
    linkQueue<Node *> que;  // 队列结点为指向Node的指针
    Node *tmp;
    T x, ldata, rdata;
    // 创建树，输入flag表示空
    cout << "\n输入根结点:";
    cin >> x;
    root = new Node(x);
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        cout << "\n输入" << tmp->data
             << "的两个儿子(" << flag
             << "表示空结点):";
        cin >> ldata >> rdata;
        if (ldata != flag)
            que.enQueue(tmp->left = new Node(ldata));
        if (rdata != flag)
            que.enQueue(tmp->right = new Node(rdata));
    }
    cout << "create completed!\n";
}

template <class T>
void binaryTree<T>::preOrder() const {
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
void binaryTree<Type>::midOrder() const {
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
void binaryTree<Type>::postOrder() const {
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
    /* code */
    return 0;
}
