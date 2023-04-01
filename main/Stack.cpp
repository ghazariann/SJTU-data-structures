#include "Stack.h"
#include <cstddef>
using namespace std;

template <class T>
void seqStack<T>::doubleSpace() {
    T *tmp = elem;
    elem = new T[2 * maxSize];
    for (int i = 0; i < maxSize; ++i)
        elem[i] = tmp[i];
    maxSize *= 2;
    delete[] tmp;
}
template <class T>
seqStack<T>::seqStack(int initSize) {
    elem = new T[initSize];
    maxSize = initSize;
    top_p = -1;
}
template <class T>
seqStack<T>::~seqStack() {  }
template <class T>
bool seqStack<T>::isEmpty() const { return top_p == -1; }
template <class T>
void seqStack<T>::push(const T &x) {
    if (top_p == maxSize - 1) doubleSpace();
    elem[++top_p] = x;
}
template <class T>
T seqStack<T>::pop() { return elem[top_p--]; }
template <class T>
T seqStack<T>::top() const { return elem[top_p]; }

// Implementation using SingleLinkedList
template <class T>
linkStack<T>::linkStack() { top_p = NULL; }

template <class T>
linkStack<T>::~linkStack() {
    node *tmp;
    while (top_p != NULL) {
        tmp = top_p;
        top_p = top_p->next;
        delete tmp;
    }
}

template <class T>
void linkStack<T>::push(const T &x) {
    top_p = new node(x, top_p);
}

template <class T>
T linkStack<T>::pop() {
    node *tmp = top_p;  // need this line to delete pointer (59)
    T x = tmp->data;
    top_p = top_p->next;
    delete tmp;
    return x;
}

template <class T>
T linkStack<T>::top() const {
    return top_p->data;
}

template <class T>
bool linkStack<T>::isEmpty() const {
    return top_p == NULL;
}

// int main(int argc, char const *argv[]) {
//     seqStack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     cout << s.top() << endl;
//     return 0;
// }
