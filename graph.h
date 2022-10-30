//
// Created by Limpol on 2022/10/24.
//

#pragma once

#include <forward_list>

template<typename T>
struct edge
{
public:
    T from;
    T to;
    int weight;

    edge() = default;

    edge(T from, T to, int weight) : from(from), to(to), weight(weight)
    {}
};

template<typename T>
class graph
{
public:
    graph() = default;

    virtual ~graph() = default;

    virtual void addEdge(T, T) = 0;

    virtual void removeEdge(T, T) = 0;

    virtual bool existEdge(T, T) = 0;

    virtual int degree(T) = 0;

    virtual int inDegree(T) = 0;

    virtual int outDegree(T) = 0;

    virtual bool directed() const = 0;

    virtual bool weighted() const = 0;

};

template<typename T>
class adjencencyWdigraph
{
public:
    adjencencyWdigraph(int Ver = 0, T thenoedge = 0)
    {
        if (Ver < 0)
            throw "Ver must be positive";
        n = Ver;
        e = 0;
        noEdge = thenoedge;
        a = new T *[n + 1];
        for (int i = 1; i <= n + 1; i++)
        {
            a[i] = new T[n + 1];
            for (int j = 1; j <= n; j++)
                a[i][j] = noEdge;
        }
    }

    ~adjencencyWdigraph()
    {
        for (int i = 1; i <= n + 1; i++)
            delete[] a[i];
        delete[] a;
    }

    int numberOfVertices() const
    { return n; }

    int numberOfEdges() const
    { return e; }

    bool existEdge(int v1, int v2) const
    {
        if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2 || a[v1][v2] == noEdge)
            return false;
        else
            return true;
    }

    void insertEdge(edge<T> *theEdge)
    {
        int v1 = theEdge->from;
        int v2 = theEdge->to;
        if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2)
            throw std::runtime_error("bad edge");
        if (a[v1][v2] == noEdge)
            e++;
        a[v1][v2] = theEdge->weight;
    }

    void insertEdge(int v1, int v2, int weight)
    {
        if (v1 < 1 || v2 < 1 || v1 > n || v2 > n || v1 == v2)
            throw std::runtime_error("bad edge");
        if (a[v1][v2] == noEdge)
            e++;
        a[v1][v2] = weight;
    }

    void removeEdge(int i, int j)
    {
        if (existEdge(i, j))
        {
            a[i][j] = noEdge;
            e--;
        }
    }

    void checkVertex(int v) const
    {
        if (v < 1 || v > n)
            throw "bad vertex";
    }

    int degree(int v) const = delete;

    virtual int inDegree(int v) const
    {
        checkVertex(v);
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][v] != noEdge)
                sum++;
        return sum;
    }

    int outDegree(int v) const
    {
        checkVertex(v);
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (a[v][i] != noEdge)
                sum++;
        return sum;
    }

    class Iterator
    {
    public:
        Iterator(T *x, int n, int v)
        {
            row = x;
            noEdge = n;
            n = v;//顶点数
            current = 1;
        }

        ~Iterator() = default;

        int next(T &theWeight)
        {
            for (int j = current; j <= n; j++)
            {
                if (row[j] != noEdge)
                {
                    current = j + 1;
                    theWeight = row[j];
                    return j;
                }
            }
            current = n + 1;
            return 0;
        }

    protected:
        T *row;
        T noEdge;
        int n;
        int current;

    };

protected:
    int n;
    int e;
    T **a;
    T noEdge;
};

template<typename T>
class linkedDigraph
{
private:
    int n, e;
    using table = std::vector<std::forward_list<T>>;
    table a;
public:
    linkedDigraph(int VertexNumber = 0)
    {
        if (VertexNumber < 0)
            throw std::range_error("can not creat a  graph with negative vertex number");
        n = VertexNumber;
        e = 0;
        a.resize(n + 1);
    }

    ~linkedDigraph()
    {
        a.clear();
    }

    bool existEdge(int i, int j) const
    {
        if (i < 1 || j < 1 || i > n || j > n || a[i][j] == -1)
            return false;
        else
            return true;
    }

    void insertEdge(int v1, int v2)
    {
        if (a[v1][v2] == -1)
        {
            a[v1].push_front(v2);
            e++;
        }
    }
    void eraseEdge(int v1, int v2)
    {
        if (a[v1][v2] != -1)
        {
            a[v1].remove(v2);
            e--;
        }
    }
    void checkVertex(int v) const
    {
        if (v < 1 || v > n)
            throw std::range_error("bad vertex");
    }
    int degree(int v) const=delete;
    int inDegree(int v) const
    {
        checkVertex(v);
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][v] != -1)
                sum++;
        return sum;
    }
    int outDegree(int v) const
    {
        checkVertex(v);
        return a[v].size();
    }
    void bfs(int v,int reach[],int label)
    {
        std::forward_list<int> q(10);
        reach[v] = label;
        q.push_front(v);
        while(!q.empty())
        {
            int w = q.front();
            q.pop_front();
            for(int u=1;u<=n;u++)
            {
                if(a[w][u]!=-1&&reach[u]==0)
                {
                    reach[u]=label;
                    q.push_front(u);
                }
            }
        }

    }
void dfs(int v,int reach[],int label)
    {
        reach[v]=label;
        for(int u=1;u<=n;u++)
        {
            if(a[v][u]!=-1&&reach[u]==0)
                dfs(u,reach,label);
        }
    }

};