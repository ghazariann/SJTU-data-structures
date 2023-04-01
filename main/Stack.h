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
