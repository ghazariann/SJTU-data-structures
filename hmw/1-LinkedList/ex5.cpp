#include <cstdlib>
#include <iostream>

using namespace std;

// structure of a node in the singly linked list
struct node {
    int data;
    node* next;
};

// function to create a new node
node* getNewNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to add a new node to the end of the list
void insertAtEnd(node** headRef, int data) {
    node* newNode = getNewNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// function to display the list
void displayList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// function to interchange the next pointers of adjacent nodes
void interchangeNextPointers(node* node1, node* node2) {
    node* temp = node2->next;
    node2->next = node1->next;
    node1->next = node2;
    node2 = temp;
}

// function to convert the linked list to (a1,an,a2,an-1,...)
void convertList(node** headRef) {
    // create a temporary node pointer and point it to the header node
    node* temp = getNewNode(-1);
    temp->next = *headRef;

    // traverse the list till the last node and update the tail node pointer
    node* tail = *headRef;
    while (tail->next != NULL)
        tail = tail->next;

    // traverse the list again and interchange the next pointers of adjacent nodes
    node* curr = temp;
    int count = 0;
    while (curr != tail && count < (int)((*headRef)->data) / 2) {
        interchangeNextPointers(curr->next, tail);  // interchange next pointers
        curr = curr->next->next;
        count++;
        tail = tail->next;  // update tail node pointer
    }

    // set the next of the second last node to NULL
    curr->next->next = NULL;

    // set the next pointers of the first and last node
    (*headRef)->next = tail;
    tail->next = temp->next->next;

    // delete the temporary node pointer
    delete temp;
}

// main function
int main() {
    node* head = NULL;
    int n, data;
    cout << "Enter n (even number) : ";
    cin >> n;

    // filling the linked list with n elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << " : ";
        cin >> data;
        insertAtEnd(&head, data);
    }

    cout << "Original List : ";
    displayList(head);

    convertList(&head);

    cout << "New List : ";
    displayList(head);
    return 0;
}