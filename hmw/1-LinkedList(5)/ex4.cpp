/*Singly linked list with header nodes (a1, a2,...an-1,an),
 n is an even number, design algorithm to converts it to (a1,an,a2,an-1,...)
 referance: https://www.geeksforgeeks.org/reverse-the-order-of-all-nodes-at-even-position-in-given-linked-list/?ref=rp
 */
#include <iostream>
using namespace std;
 
template <typename T>
struct Node {
    T data;
    Node<T> * next;
    Node(T data, Node<T> * next=nullptr) : data(data), next(next) {};
};

template <typename T>
Node<T>* reverseEven(Node<T>* head)
{
    Node<T>* even = nullptr;
 
    Node<T>* odd = head;
 
    if (!odd || !odd->next || !odd->next->next)
        return odd; // same list if 0, 1 or 2 Node<T>s
    
    // construct odd head and reversed-even lists
    while (odd && odd->next) {
 
    
        Node<T>* tmp = odd->next;
        odd->next = tmp->next; // odd->next->next;
        tmp->next = even;
        even = tmp;
        odd = odd->next;
    }
    odd = head;
 
    // Merge
    while (even) {
 
        Node<T>* tmp = even->next;
        even->next = odd->next;
        odd->next = even;
        even = tmp;
        odd = odd->next->next;
    }
 
    return head;
}
 
template <typename T>
void print( Node<T>* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
int main()
{
    Node<int>* head = nullptr;
     head = new  Node<int>(8, head);
    head = new  Node<int>(7, head);
    head = new  Node<int>(6, head);
    head = new  Node<int>(5, head);
    head = new  Node<int>(4, head);
    head = new  Node<int>(3, head);
    head = new  Node<int>(2, head);
    head = new  Node<int>(1, head);
 
    head = reverseEven(head);
    print(head);
 
    return 0;
}