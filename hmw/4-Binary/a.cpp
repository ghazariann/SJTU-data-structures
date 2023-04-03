#include <iostream>
#include "../../main/Queue.cpp"   

using namespace std;

int main(int argc, char const *argv[]) {
    seqQueue<int> q1(6);
    // seqQueue<int> q2(10);
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);

    q1.deQueue();
    q1.deQueue();
    q1.enQueue(40);
    q1.enQueue(50);
    q1.deQueue();

    for (int i = 0; i < 10; ++i) {
        q1.enQueue(i);
        q1.enQueue(i+1);
        q1.deQueue();
        // q2.enQueue(i*10+1);
    }
    cout << q1.length() << endl;
    for (int i = 0; i < 10; ++i) {
        cout << q1.deQueue() << " ";
        // cout << q2.deQueue() << " ";
    }
    return 0;
}

