#include <string.h>
#include <iostream>
using namespace std;

class Node {
   public:
    int coff, exp;
    Node* next;
    Node() { next = NULL; }
    Node(int n1, int n2, Node* p = NULL) : coff(n1), exp(n2), next(p) {}
};

Node * add(Node* exp1, Node* exp2) {
     // expecting exponent ascending order
    Node *res, *p, *tmp;
    res = p = new Node();
    exp1 = exp1->next;
    exp2 = exp2->next;  
    while (exp1 != NULL && exp2 != NULL) {
        if (exp1->exp < exp2->exp) {
            p->next = new Node(exp1->coff, exp1->exp);  // 根据实际情况决定是否复制结点
            p = p->next;
            exp1 = exp1->next;
        } else if (exp1->exp > exp2->exp) {
            p->next = new Node(exp2->coff, exp2->exp);  //
            p = p->next;
            exp2 = exp2->next;
        } else if (exp1->coff + exp2->coff != 0) {
            p->next = new Node(exp1->coff + exp2->coff, exp2->exp);  //
            p = p->next;
            exp1 = exp1->next;exp2 = exp2->next;
        } else {
            exp1 = exp1->next; exp2 = exp2->next;
        }
    }
    if (exp1 == NULL) tmp = exp2;
    else tmp = exp1;
    while (tmp != NULL) {
        p->next = new Node(tmp->coff, tmp->exp);
        tmp = tmp->next;
        p = p->next;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    Node *p1,*p2, *p3;
   
    p1 = new Node(); 
    p1->next = new Node(1,0);  
    p1->next->next = new Node(5,2);
    p1->next->next->next = new Node(2,4);
    p1->next->next->next->next = new Node(1, 5);

    p2 = new Node();
    p2->next = new Node(1,1);  
    p2->next->next = new Node(1,3);
    p2->next->next->next = new Node(2,5);
     p2->next->next->next = new Node(2,6);
    // p2->next->next->next->next = new Node(2, 0);
 
    p3 = add(p1, p2);
    while (p3->next != NULL) {
        cout << p3->next->coff << " " << p3->next->exp << endl;
        p3 = p3->next;
    }
    return 0;
}
