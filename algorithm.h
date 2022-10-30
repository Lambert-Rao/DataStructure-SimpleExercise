//
// Created by Limpol on 2022/10/27.
//

#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include <array>
#include "graph.h"

namespace GREEDY
{
    using namespace std;
    //pseudo code
    /*
    bool topologicalOrder(int *theOrder)
    {
        //?
        int n = numberOfVertices();
        int *inDegree = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            vertexIterator <T> *iter = Iterator(i);
            int u;
            while ((u = iter->next()) != 0)
                inDegree[u]++;
        }
        std::stack<int> s;
        for (int i = 1; i <= n; i++)
            if (inDegree[i] == 0)
                s.push(i);
        int j = 0;
        while (!s.empty())
        {
            int v = s.top();
            s.pop();
            theOrder[j++] = v;
            vertexIterator <T> *iter = Iterator(v);
            int u;
            while ((u = iter->next()) != 0)
            {
                inDegree[u]--;
                if (inDegree[u] == 0)
                    s.push(u);
            }
        }
        return j == n;
    }*/
    //pseudo code p432
    /*
    void bipartite_cover()
    {
        int coversize(0);
        int thecover;
        int newVertices[i]=degree[i];
        bool covered[i]=false;
        for(;newVertices[i]>0)
        {
            int maxVertex;
            thecover[coversize++]=maxVertex;
            for(j)
            {
                if(!covered[j])
                    maxVertex=j;
            }
        }
    }
    */
    void dijkstra(const adjencencyWdigraph<int> &g, int v, int dist[], int path[])
    {
        int n = g.numberOfVertices();
        bool *sign = new bool[n + 1];
        for (int i = 1; i <= n; i++)
        {
            dist[i] = g.weight(v, i);
            sign[i] = false;
            if (dist[i] == g.no_edge())
                path[i] = 0;
            else
                path[i] = v;
        }
        dist[v] = 0;
        sign[v] = true;
        for (int i = 2; i <= n; i++)
        {
            int u = v;//u is the nearest vertex
            int minDist = g.no_edge();
            for (int w = 1; w <= n; w++)//find the nearest vertex
                if (!sign[w])
                    if (dist[w] < minDist)
                    {
                        u = w;
                        minDist = dist[w];
                    }
            sign[u] = true;
            for (int w = 1; w <= n; w++)//update the dist and path
                if (!sign[w])
                {
                    int d = dist[u] + g.weight(u, w);
                    if (dist[w] > d)
                    {
                        dist[w] = d;
                        path[w] = u;
                    }
                }
        }
        delete[] sign;
    }

    bool kruskal(const adjencencyWdigraph<int> &graph, edge<int> *result)
    {
        int ver_num = graph.numberOfVertices();
        int edg_num = graph.numberOfEdges();
        int index = 0;
        std::vector<edge<int>> edges(edg_num);
        for (int i = 1; i <= ver_num; i++)
        {
            auto *iter = graph.iterator(i);
            int j;
            int weight;
            while ((j = iter->next(weight)) != 0)
                if (i < j)
                    edges[++index] = edge<int>(i, j, weight);
        }
        std::sort(edges.begin(), edges.end(), [](const edge<int> &a, const edge<int> &b)
        { return a.weight < b.weight; });
        while (edges.size() < edg_num - 1)
        {
            edge<int> e = edges.back();
            edges.pop_back();
            //判断是否有环
            if (!graph.isCycle(e))
            {
                result[edges.size()] = e;
            }
        }
        return (edges.size() == 1);
    }
}

namespace Algorithm_Test
{
    using namespace std;

    void dijkstra()
    {
        adjencencyWdigraph<int> a(10);
        a.insertEdge(1, 2, 1);
        a.insertEdge(7, 1, 1);
        cout << a.inDegree(1) << endl << a.outDegree(1) << endl;
        int *dist = new int[10];
        int *path = new int[10];
        GREEDY::dijkstra(a, 1, dist, path);
    }

}