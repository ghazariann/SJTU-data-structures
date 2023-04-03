// #pragma once
template <class elemType>
class queue {
   public:
    virtual bool isEmpty() = 0;                   // 判队空
    virtual void enQueue(const elemType &x) = 0;  // 进队
    virtual elemType deQueue() = 0;               // 出队
    virtual elemType getHead() = 0;               // 读队头元素
    virtual ~queue() {}                           // 虚析构函数
};

template <class elemType>
class seqQueue : public queue<elemType> {
   private:
    elemType *elem;
    int maxSize;
    int front, rear;
    void doubleSpace();

   public:
    seqQueue(int size = 10);
    ~seqQueue();
    bool isEmpty();
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead();
    int length();

};

template <class elemType>
class linkQueue : public queue<elemType> {
   private:
    struct node {
        elemType data;
        node *next;
        node(const elemType &x, node *N = nullptr) {
            data = x;
            next = N;
        }
        node() : next(nullptr) {}
        ~node() {}
    };
    node *front, *rear;

   public:
    linkQueue();
    ~linkQueue();
    bool isEmpty();
    void enQueue(const elemType &x);
    elemType deQueue();
    elemType getHead();

};

