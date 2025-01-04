#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 边，记录边两边结点，记录边的长度
struct Edge
{
    int src;
    int dest;
    int weight;
};

// 并查集结构体,用于检查环
struct DisjointSets
{
    vector<int> parent;
    vector<int> rank;
    // 构造函数,相当于make_set()
    DisjointSets(int n)
    {
        // 初始化指针指向自己，且rank初始化为0
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        return parent[x] == x ? x : find(parent[x]);
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
        {
            return;
        }
        else
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                rank[rootY]++;
                parent[rootX] = rootY;
            }
        }
    }
};

vector<Edge> Kruskal(vector<Edge> &edges, int numVertices)
{
    DisjointSets ds(numVertices); // 初始化那些结点
    vector<Edge> mst;             // 存储最小生成树的边
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; }); // 按照从小到大将边排序
    for (const Edge &edge : edges)
    {
        int one = edge.src;
        int another = edge.dest;
        if (ds.find(one) != ds.find(another)) // 判断加入这条边后有没有成环
        {
            mst.push_back(edge);    // 加入最小生成树
            ds.unite(one, another); // 将两个点加入到同一个并查集中
        }
    }
    return mst;
}

int main()
{
    // cout << "test" << endl;
    //  示例图的边列表表示
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    int numVertices = 4; // 顶点数量

    vector<Edge> mst = Kruskal(edges, numVertices);

    // 输出最小生成树的边
    cout << "最小生成树的边:" << endl;
    for (const Edge &edge : mst)
    {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }

    return 0;
}