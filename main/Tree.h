template <class T>
class tree {
   public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T root(T flag) const = 0;  // 非空，返回根节点；空树，返回flag
    virtual T parent(T x, T flag) const = 0;
    virtual T child(T x, int i, T flag) const = 0;
    virtual void remove(T x, int i) = 0;
    virtual void traverse() const = 0;
};

template<class T>
class bTree {
public:
virtual void clear() = 0;
virtual bool isEmpty() const = 0;
virtual T Root(T flag) const = 0;
virtual T parent(T x, T flag) const = 0;
virtual T lchild(T x, T flag) const = 0;
virtual T rchild(T x, T flag) const = 0;
virtual void delLeft(T x) = 0;
virtual void delRight(T x) = 0;
virtual void preOrder() const = 0;
virtual void midOrder() const = 0;
virtual void postOrder() const= 0;
virtual void levelOrder() const = 0;
};

