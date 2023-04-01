#include <stddef.h>

#include "seqList.h"

template <class T>
class sLinkList : public list<T> {
   private:
    struct node {
        T data;
        node *next;
        node(const T &x, node *n = NULL) {
            data = x, next = n;
        }
        node() : next(NULL) {}
        ~node() {}
    };

    node *head;
    int currentLength;
    node *move(int i) const;  // Return the address of the ith element

   public:
    sLinkList();
    ~sLinkList() {
        clear();
        delete head;
    }
    void clear();
    int length() const { return currentLength; }
    void insert(int i, const T &x);
    void remove(int i);
    int search(const T &x) const;
    T visit(int i) const;
    void traverse() const;
    void erase(int i);
    int size();
    void erase(int i, int j);
    void erase_xy(int i, int j);
    void reverse();
};

template <class T>
class dLinkList : public list<T> {
   private:
    struct node {  
        T data;
        node *prev, *next;
        node(const T &x, node *p = NULL, node *n = NULL) {
            data = x;
            next = n;
            prev = p;
        }
        node() : next(NULL), prev(NULL) {}
        ~node() {}
    };
    node *head, *tail;        
    int currentLength;        
    node *move(int i) const; 

   public:
    dLinkList();
    ~dLinkList() {
        clear();
        delete head;
        delete tail;
    }
    void clear();
    int length() const { return currentLength; }
    void insert(int i, const T &x);
    void remove(int i);
    int search(const T &x) const;
    T visit(int i) const;
    void traverse() const;
    void erase(int i);
};