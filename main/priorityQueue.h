#include "queue.h"
#include <iostream>
using namespace std;

template <class T>
class priorityQueue:public queue<T>{
public:
    priorityQueue(int capacity = 100) {
        array = new T[capacity];
        maxSize = capacity;
        currentSize = 0;
    }  // 顺序表初始化
    priorityQueue(const T data[], int size);  // 建堆过程
    ~priorityQueue() { delete[] array; }
    bool isEmpty()  { return currentSize == 0; }
    void enQueue(const T& x);  // 入队
    T deQueue();
    T getHead() { return array[1]; }  // array[0]做了哨兵
private:
    int currentSize;
    T* array;
    int maxSize;
    void doubleSpace();
    void buildHeap();
    void percolateDown(int hole);
};

template <class Type>
void priorityQueue<Type>::buildHeap() {
    for (int i = currentSize / 2; i > 0; i--)
        percolateDown(i);
}
template<class T> priorityQueue<T>::priorityQueue(const T *data, int size): maxSize(size + 10), currentSize(size) {
    array = new T[maxSize];
    for (int i = 0; i < size; i++)
        array[i + 1] = data[i];
    buildHeap();
}

template <class Type>
void priorityQueue<Type>::doubleSpace() {
    Type* tmp = array;
    maxSize *= 2;
    array = new Type[maxSize];
     for (int i = 0 ; i <= currentSize; ++i)
                    array[i] = tmp[i];
    delete tmp;
}

template <class T>
void priorityQueue<T>::enQueue(const T& x) { // add
    if (currentSize == maxSize - 1) doubleSpace();
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole / 2]; hole /= 2) //heapify 
        array[hole] = array[hole / 2];
    array[hole] = x;
}

template <class T> 
T priorityQueue<T>::deQueue() { // poll
    T minItem;
    minItem = array[1];  // 堆顶下标为1或者0，可自行定义
    array[1] = array[currentSize--];
    percolateDown(1);
    return minItem;
}

template <class Type>
void priorityQueue<Type>::percolateDown(int hole) { // sink
    int child;
    Type tmp = array[hole];
    for (; hole * 2 <= currentSize; hole = child) {
        child = hole * 2;
        if (child != currentSize && array[child + 1] < array[child])
            child++; // smallest child
        if (array[child] < tmp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = tmp;
}

