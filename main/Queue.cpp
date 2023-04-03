#include "Queue.h"
#include <iostream>
using namespace std;    


template <class elemType>
seqQueue<elemType>::seqQueue(int size) {
    elem = new elemType[size];
    maxSize = size;
    front = rear = 0;
}
template <class elemType>
seqQueue<elemType>::~seqQueue() {
    delete[] elem;
}

template <class elemType>
void seqQueue<elemType>::doubleSpace() {
    elemType *tmp = elem;
    elem = new elemType[2 * maxSize];
    for (int i = 1; i < maxSize; ++i)
        elem[i] = tmp[(front + i) % maxSize];
    front = 0;
    rear = maxSize - 1;
    maxSize *= 2;
    delete tmp;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &x) {
    if ((rear + 1) % maxSize == front)
        doubleSpace();
    rear = (rear + 1) % maxSize;
    elem[rear] = x;
}
template <class elemType>
elemType seqQueue<elemType>::deQueue() {
    front = (front + 1) % maxSize;
    return elem[front];
}

template <class elemType>
bool  seqQueue<elemType>::isEmpty() {
    return front == rear;
}

template <class elemType>
elemType seqQueue<elemType>::getHead()
{
return elem[(front + 1) % maxSize];
}

template <class elemType>
int seqQueue<elemType>::length()
{
return (rear-front+maxSize)%maxSize;
}

//--------------------------------------------------------------------------------------------
template <class elemType>
linkQueue<elemType>::linkQueue() {
    front = rear = nullptr;
}

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x) {
    if (rear == nullptr)
        front = rear = new node(x);
    else
        rear = rear->next = new node(x);
}
template <class elemType>
elemType linkQueue<elemType>::deQueue() {  // 空队列处理？
    node *tmp = front;
    elemType value = front->data;
    front = front->next;
    if (front == nullptr) rear = nullptr;  // 最后一个元素出队
    delete tmp;
    return value;
}
template <class elemType>
bool linkQueue<elemType>::isEmpty()  {
    return front == nullptr;
}
template <class elemType>
elemType linkQueue<elemType>::getHead()  {
    return front->data;
}
template <class elemType>
linkQueue<elemType>::~linkQueue() {
    node *tmp;
    while (front != nullptr) {
        tmp = front;
        front = front->next;
        delete tmp;
    }
}
// int main(int argc, char const *argv[]) {
//     seqQueue<int> q1(6);
//     // seqQueue<int> q2(10);
//     q1.enQueue(10);
//     q1.enQueue(20);
//     q1.enQueue(30);

//     q1.deQueue();
//     q1.deQueue();
//     q1.enQueue(40);
//     q1.enQueue(50);
//     q1.deQueue();

//     for (int i = 0; i < 10; ++i) {
//         q1.enQueue(i);
//         q1.enQueue(i+1);
//         q1.deQueue();
//         // q2.enQueue(i*10+1);
//     }
//     cout << q1.length() << endl;
//     for (int i = 0; i < 10; ++i) {
//         cout << q1.deQueue() << " ";
//         // cout << q2.deQueue() << " ";
//     }
//     return 0;
// }
