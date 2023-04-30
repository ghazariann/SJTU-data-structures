#include <stddef.h>

template <class T>
class list
{
public:
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual void insert(int i, const T &x) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const T &x) const = 0;
    virtual T visit(int i) const = 0;
    virtual void traverse() const = 0;
    // virtual ~list();
};

template <class T>
class seqList : public list<T>
{
private:
    T *data;
    int currentLength;
    int maxSize;
    void doubleSpace();

public:
    seqList(int initSize = 10);
    ~seqList();
    void clear();
    int length() const;
    void insert(int i, const T &x);
    void remove(int i);
    int search(const T &x) const;
    T visit(int i) const;
    void traverse() const;
    void erase(int i);
};

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