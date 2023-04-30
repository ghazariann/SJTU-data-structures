#include <iostream>
using namespace std;
//./exe/call

// usefull 
//https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl 
// see: How can I avoid linker errors with my template classes?
// template class seqQueue<int>;
// template class linkQueue<int>;
// template seqQueue<int>::seqQueue(int size);

// seqList
// #include "seqList.h"
// int main(int argc, char const *argv[])
// {
//     seqList<int> s = seqList<int>(10);
//     s.insert(0, 10);
//     s.insert(1, 20);
//     s.insert(1, 30);
//     s.insert(2, 40);
//     s.traverse();
//     s.remove(1);
//     s.traverse();
//     s.insert(2,10);
//     s.traverse();
//     s.erase(1);
//     s.traverse();
//     int res = s.visit(0);
//     cout << endl << res << endl;
//     const int a = 10;
//     int idx = s.search(a);
//     cout << idx << endl;
//     return 0;
// }

// linkedList
// #include "LinkedList.h"
// int main(int argc, char const *argv[]) {
//     /* code */
//     sLinkList<int> l = sLinkList<int>();
    // dLinkList<int> l = dLinkList<int>();
//     l.insert(0, 10);
//     l.insert(1, 20);
//     l.insert(2, 30);
//     l.insert(3, 40);
//     l.insert(4, 50);
//     l.insert(5, 20);
//     l.insert(6, 20);
//     l.insert(5, 40);
//     l.insert(8, 50);
//     l.traverse();
//     // l.remove(1);
//     // l.traverse();
//     // l.insert(2, 10);
//     // l.traverse();
//     // l.erase(1);
//     // l.traverse(); 
//     // int res = l.visit(0);
//     // cout << endl
//     //      << res << endl;
//     // const int a = 10;
//     // int idx = l.search(a);
//     // cout << idx << endl;
//     // l.erase(30, 50);
//     l.reverse();
//     l.traverse();
//     return 0;
// }

// queue
// #include "Queue.h"
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

// stack
// #include "Stack.h"
// int main(int argc, char const *argv[]) {
//     seqStack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     cout << s.top() << endl;
//     return 0;
// }

// tree
#include "BinaryTree.h"
int main(int argc, char const *argv[]) {
    binaryTree<char> tree;
    // cin 1 ,2 3, 4 5, @ @, @ @, @ @
    tree.createTree('@');
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    tree.levelOrder();
    printTree(tree, '@');
    tree.delLeft ('2');
    // tree.delRight('3');
    // tree.delLeft ('C');
    printTree(tree,'@');
    return 0;
}