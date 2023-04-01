#include <string.h>
#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    Node() { next = NULL; }
    Node(int data, Node* p=NULL) : data(data), next(p) {}
};

// 12.Given two ascending linked lists of length m and n respectively, 
// if they are merged into a descending linked list of length m+n, what is the time complexity in the worst case?
// O(m+n)
Node * sort(Node* p1, Node* p2) {
    Node *res, *p, *tmp;
    res = p = new Node();
    // p1 = p1->next;
    // p2 = p2->next;  
    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            p->next = new Node(p1->data);  // 根据实际情况决定是否复制结点
            p = p->next;
            p1 = p1->next;
        } else  {
            p->next = new Node(p2->data);  //
            p = p->next;
            p2 = p2->next;
        }
    }
   
    tmp = p1 == NULL? p2:p1;

    while (tmp != NULL) {
        p->next = new Node(tmp->data);
        tmp = tmp->next;
        p = p->next;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    Node *p1,*p2, *p3;
    p1 = new Node(1); 
    p1->next = new Node(3);  
    p1->next->next = new Node(4);
    p1->next->next->next = new Node(7);

    p2 = new Node(-2);
    p2->next = new Node(1);
    p2->next->next = new Node(5);
    p2->next->next->next  = new Node(8);
    
    p3 = sort(p1, p2);
    while (p3->next != NULL) {
        cout << p3->next->data << endl;
        p3 = p3->next;
    }


    delete p2->next->next->next, p2->next->next, p2->next, p2;
    delete p1->next->next->next, p1->next->next, p1->next, p1;
    return 0;
}
