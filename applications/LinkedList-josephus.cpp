#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int d, node *n = nullptr) {
        data = d;
        next = n;
    }
};

int main() {
    node *head, *p, *q;
    int n, i;
    cout << "input n:";
    cin >> n;
    head = p = new node(0);
    for (i = 1; i < n; ++i)
        p = p->next = new node(i);

    p->next = head;
    q = head;
    while (q->next != q) {
        p = q->next;
        q = p->next;

        p->next = q->next;
        cout << q->data << " ";
        delete q;
        q = p->next;
    }
    cout << "Won:" << q->data << endl;
    return 0;
}