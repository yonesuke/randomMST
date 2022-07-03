#include <vector>
#include <algorithm>

#include "unionfind.hpp"

class Edge{
public:
    int u;
    int v;
    double cost;

    bool operator < (const Edge& other) const
    {
        return (cost < other.cost);
    }
};

class Kruskal{
public:
    UnionFind uf;
    double sum;
    std::vector<Edge> edges;
    int v;

    Kruskal(int v_, const std::vector<Edge>& edges_);
    void calcMST();
};

Kruskal::Kruskal(int v_, const std::vector<Edge>& edges_)
{
    v = v_;
    edges = edges_;
    UnionFind uf;

    calcMST();
}

void Kruskal::calcMST()
{
    sum = 0.0;
    uf.init(v);
    std::sort(edges.begin(), edges.end());
    for (Edge edge: edges)
    {
        if (uf.unite(edge.u, edge.v))
        {
            sum += edge.cost;
        }
    }
}

