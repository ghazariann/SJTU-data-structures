#include <cstddef>
template <class T>
class stack {
   public:
    virtual bool isEmpty() const = 0;
    virtual void push(const T &x) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual ~stack() {}
};

template <class T>
class seqStack : public stack<T> {
   private:
    T *elem;
    int top_p;  // 栈顶
    int maxSize;
    void doubleSpace();

   public:
    seqStack(int initSize = 10);
    ~seqStack();
    bool isEmpty() const;
    void push(const T &x);
    T pop();
    T top() const;
};

template <class T>
class linkStack : public stack<T> {
   private:
    struct node {
        T data;
        node *next;
        node(const T &x, node *N = NULL) {
            data = x;
            next = N;
        }
        node() : next(NULL) {}
        ~node() {}
    };
    node *top_p;

   public:
    linkStack();
    ~linkStack();
    bool isEmpty() const;
    void push(const T &x); //引用传递，有时可省空间
    T pop();
    T top() const;
};
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
