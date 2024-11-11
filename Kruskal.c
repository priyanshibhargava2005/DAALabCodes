#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct edge
{
    int u, v, w;
};

int findParent(int node, vector<int> &parent)
{
    if (node == parent[node])
    {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    if (rootU != rootV)
    {
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(int v, vector<edge> &edges)
{
    vector<int> parent(v);
    vector<int> rank(v, 0);

    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end(), [](edge a, edge b)
         { return a.w < b.w; });
    vector<edge> mst;
    int mstweight = 0;

    for (edge &e : edges)
    {
        if (findParent(e.u, parent) != findParent(e.v, parent))
        {
            mst.push_back(e);
            mstweight += e.w;
            unionSets(e.u, e.v, parent, rank);
        }
    }
    cout << "Edges in MST:" << endl;
    for (edge &e : mst)
    {
        cout << e.u << " - " << e.v << " (Weight: " << e.w << ")" << endl;
    }
    cout << "Total weight of MST: " << mstweight << endl;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<edge> edges(E);
    for (int i = 0; i < E; i++)
    {
        cout << "Enter edge " << i + 1 << " (u, v, weight): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    kruskal(V, edges);

    return 0;
}