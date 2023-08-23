#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node() : next(nullptr) {};
    Node(char data) : data(data), next(nullptr) {};
};
int length(Node* str) {
    int length = 0;
    while (str->next != nullptr) {
        length++;
        str = str->next;
    }
    return length;
}

Node* findCommonSuffix(Node* str1, Node* str2) {
    int len1 = length(str1);
    int len2 = length(str2);

    // move the pointer to the same length
    if (len1 > len2) {
         while (len1 > len2) {
            str1 = str1->next;
            len1--;
        }
    }
    else{
        while (len1 < len2) {
            str2 = str2->next;
            len2--;
        }

    } 
    Node* ptr1 = str1;
    Node* ptr2 = str2;

    while (ptr1 != ptr2 && ptr1 != nullptr && ptr2 != nullptr) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1;
}


int main(int argc, char const *argv[])
{   
    Node * suf = new Node('i');
    suf->next = new Node('n');
    suf->next->next = new Node('g');

    Node* str1 = new Node('l');
    str1->next = new Node('o');
    str1->next->next = new Node('a');
    str1->next->next->next = new Node('d');
    str1->next->next->next->next = suf ;

    Node* str2 = new Node('b');
    str2->next = new Node('e');
    str2->next->next = suf;

    Node* res = findCommonSuffix(str1, str2);
    if (res)
        cout << res->data << endl; 
    else
        cout << "No common suffix!" << endl;

    delete res, suf, str1->next->next->next, str1->next->next, str1->next, str1, str2->next, str2;
    return 0;
}
