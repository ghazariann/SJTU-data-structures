template <class TypeOfVer, class TypeOfEdge>
class graph
{
public:
    virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
    virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
    virtual bool exist(TypeOfVer x, TypeOfVer y);
    const = 0 : int numOfVer() const { return Vers; }
    int numOfEdge() const { return Edges; }

protected:
    int Vers, Edges;
};

template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph : public graph<TypeOfVer, TypeOfEdge>
{
public:
    adjMatrixGraph(int vSize, const TypeOfVer d[],
                   const TypeOfEdge noEdgeFlag);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const;
    ~adjMatrixGraph();

private:
    TypeOfEdge **edge; // 存放邻接矩阵
    TypeOfVer *ver;    // 存放结点值
    TypeOfEdge noEdge; // 邻接矩阵中的∞值
    int find(TypeOfVer v) const
    {
        for (int i = 0; i < Vers; ++i)
            if (ver[i] == v)
                return i;
    }
};

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::adjMatrixGraph(int vSize, const TypeOfVer d[], TypeOfEdge noEdgeFlag)
{
    int i, j;
    Vers = vSize;
    Edges = 0;
    noEdge = noEdgeFlag;
    ver = new TypeOfVer[vSize];
    for (i = 0; i < vSize; ++i)
        ver[i] = d[i];
    edge = new TypeOfEdge *[vSize];
    for (i = 0; i < vSize; ++i)
    {
        edge[i] = new TypeOfEdge[vSize];
        for (j = 0; j < vSize; ++j)
            edge[i][j] = noEdge;
    }
}