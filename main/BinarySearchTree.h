// static search
template <class KEY, class OTHER>
class SET
{
public:
    KEY key;
    OTHER other;
};
// SET<int, std::string> mySet(1, "Hello");
//     std::cout << "Key: " << mySet.key << ", Other: " << mySet.other << std::endl;
template <class KEY, class OTHER>
int seqSearch(SET<KEY, OTHER> data[], int size, const KEY &x)
{
    data[0].key = x;
    for (int i = size; x != data[i].key; --i)
        ;
    return i;
}

template <class KEY, class OTHER>
int binarySearch(SET<KEY, OTHER> data[],
                 int size, const KEY &x)
{
    int low = 1, high = size, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == data[mid].key)
            return mid;
        if (x < data[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}
// ----------------------------------------------
template <class KEY, class OTHER>
class dynamicSearchTable
{
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0:;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTable(){};
};

template <class KEY, class OTHER>
class BinarySearchTree : public dynamicSearchTable<KEY, OTHER>
{
private:
    struct BinaryNode
    {
        SET<KEY, OTHER> data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const SET<KEY, OTHER> &thedata,
                   BinaryNode *lt = NULL, BinaryNode *rt = NULL)
            : data(thedata), left(lt), right(rt) {}
    };
    BinaryNode *root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinaryNode *find(const KEY &x) const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);

private:
    void insert(const SET<KEY, OTHER> &x, BinaryNode *&t);
    void remove(const KEY &x, BinaryNode *&t);
    SET<KEY, OTHER> *find(const KEY &x, BinaryNode *t) const;
    void makeEmpty(BinaryNode *t);
};

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY &x, BinaryNode *t) const
{
    if (t == NULL || t->data.key == x)
        return (t);
    if (x < t->data.key)
        return find(x, t->left);
    else
        return find(x, t->right);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY,OTHER> &x, BinaryNode *&t)
{
    if (t == NULL)
        t = new BinaryNode(x, NULL, NULL);
    else if (x.key < t->data.key)
        insert(x, t->left);
    else if (t->data.key < x.key)
        insert(x, t->right);
}