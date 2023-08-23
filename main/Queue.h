template <class elemType> class queue {
public:
  virtual bool isEmpty() = 0;                  // 判队空
  virtual void enQueue(const elemType &x) = 0; // 进队
  virtual elemType deQueue() = 0;              // 出队
  virtual elemType getHead() = 0;              // 读队头元素
  virtual ~queue() {}                          // 虚析构函数
};

template <class elemType> class seqQueue : public queue<elemType> {
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

template <class elemType> class linkQueue : public queue<elemType> {
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

template <class elemType> seqQueue<elemType>::seqQueue(int size) {
  elem = new elemType[size];
  maxSize = size;
  front = rear = 0;
}

template <class elemType> seqQueue<elemType>::~seqQueue() { delete[] elem; }

template <class elemType> void seqQueue<elemType>::doubleSpace() {
  elemType *tmp = elem;
  elem = new elemType[2 * maxSize];
  for (int i = 1; i < maxSize; ++i)
    elem[i] = tmp[(front + i) % maxSize];
  front = 0;
  rear = maxSize - 1;
  maxSize *= 2;
  delete tmp;
}

template <class elemType> void seqQueue<elemType>::enQueue(const elemType &x) {
  if ((rear + 1) % maxSize == front)
    doubleSpace();
  rear = (rear + 1) % maxSize;
  elem[rear] = x;
}
template <class elemType> elemType seqQueue<elemType>::deQueue() {
  front = (front + 1) % maxSize;
  return elem[front];
}

template <class elemType> bool seqQueue<elemType>::isEmpty() {
  return front == rear;
}

template <class elemType> elemType seqQueue<elemType>::getHead() {
  return elem[(front + 1) % maxSize];
}

template <class elemType> int seqQueue<elemType>::length() {
  return (rear - front + maxSize) % maxSize;
}

//--------------------------------------------------------------------------------------------
template <class elemType> linkQueue<elemType>::linkQueue() {
  front = rear = nullptr;
}

template <class elemType> void linkQueue<elemType>::enQueue(const elemType &x) {
  if (rear == nullptr)
    front = rear = new node(x);
  else
    rear = rear->next =
        new node(x); // create new node in rear->next and assign rear to it
}
template <class elemType>
elemType linkQueue<elemType>::deQueue() { // 空队列处理？
  node *tmp = front;
  elemType value = front->data;
  front = front->next;
  if (front == nullptr)
    rear = nullptr; // 最后一个元素出队
  delete tmp;
  return value;
}
template <class elemType> bool linkQueue<elemType>::isEmpty() {
  return front == nullptr;
}
template <class elemType> elemType linkQueue<elemType>::getHead() {
  return front->data;
}
template <class elemType> linkQueue<elemType>::~linkQueue() {
  node *tmp;
  while (front != nullptr) {
    tmp = front;
    front = front->next;
    delete tmp;
  }
}

// template <class elemType>
// class linkQOueue
// {
// private:
//     struct node
//     {
//         elemType data;
//         node #next;
//         node(const elemType &x, node *N = NULL) { data = 交 next = N; }
//         nodef() : next(NULD) 人
//                   ~node() 人