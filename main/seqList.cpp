#include "seqList.h"
#include <iostream>
using namespace std;

template <class T>
seqList<T>::~seqList() { delete[] data; };

template <class T>
void seqList<T>::clear()
{
    currentLength = 0;
};

template <class T>
int seqList<T>::length() const
{
    return currentLength;
}

template <class T>
T seqList<T>::visit(int i) const
{
    return data[i];
}

template <class T>
void seqList<T>::traverse() const
{
    cout << endl;
    for (int i = 0; i < currentLength; ++i)
        cout << data[i] << ' ';
}

template <class T>
seqList<T>::seqList(int initSize)
{
    data = new T[initSize];
    maxSize = initSize;
    currentLength = 0;
}

template <class T>
int seqList<T>::search(const T &x) const
{   
    int i = 0;
    for (i = 0; i < currentLength && data[i] != x; ++i);
    
    if (i == currentLength)
        return -1;
    else
        return i;
};

// *IMPORTANT
template <class T>
void seqList<T>::doubleSpace()
{
    T *tmp = data;
    maxSize *= 2;
    data = new T[maxSize];
    for (int i = 0; i < currentLength; ++i)
        data[i] = tmp[i];
    delete[] tmp;
}
template <class T>
void seqList<T>::insert(int i, const T &x)
{
    if (currentLength == maxSize)
        doubleSpace();
    for (int j = currentLength; j > i; j--)
        data[j] = data[j - 1];
    data[i] = x;
    ++currentLength;
}

template <class T>
void seqList<T>::remove(int i)
{
    for (int j = i; j < currentLength - 1; j++)
        data[j] = data[j + 1];
    --currentLength;
}
template <class T>
void seqList<T>::erase(int i)
{
    T tmp = data[i];
    int cnt = 0;
    for (int j = 0; j < currentLength; ++j)
        if (data[j] == tmp)
            ++cnt;
        else
            data[j - cnt] = data[j];
    currentLength -= cnt;
}

int main(int argc, char const *argv[])
{

    seqList<int> s = seqList<int>(10);
    s.insert(0, 10);
    s.insert(1, 20);
    s.insert(1, 30);
    s.insert(2, 40);
    s.traverse();

    s.remove(1);
    s.traverse();

    s.insert(2,10);
    s.traverse();

    s.erase(1);
    s.traverse();

    int res = s.visit(0);
    cout << endl << res << endl;
    const int a = 10;
    int idx = s.search(a);
    cout << idx << endl;
    return 0;
}
