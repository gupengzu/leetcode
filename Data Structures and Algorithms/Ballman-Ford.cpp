#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 边的结构体，用于表示图中的边
struct Edge
{
    int src;
    int dest;
    int weight;
};

// bellman-Ford算法的实现
void bellmanFord(const vector<Edge> &edges, int numVertices, int source)
{
    // 存储从源点到各个顶点的最短距离，初始化为无穷大
    vector<int> dist(numVertices, INT_MAX);
    dist[source] = 0;

    // 进行numVertices-1次迭代，对所有边进行松弛操作
    for (int i = 0; i < numVertices - 1; ++i)
    {
        bool updated = false;
        for (const Edge &edge : edges)
        {
            int u = edge.src;
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                updated = true;
            }
        }
        // 如果没有状态更新，提前终止
        if (!updated)
        {
            break;
        }
    }

    // 检查是否存在负权重环
    for (const Edge &edge : edges)
    {
        int u = edge.src;
        int v = edge.dest;
        int weight = edge.weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "图中存在负权重环" << endl;
            return;
        }
    }

    // 输出最短路径
    cout << "顶点 " << source << " 到其他顶点的最短路径距离：" << endl;
    for (int i = 0; i < numVertices; ++i)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "顶点 " << i << " 不可达" << endl;
        }
        else
        {
            cout << "到顶点 " << i << " 的距离为 " << dist[i] << endl;
        }
    }
}

int main()
{
    // 示例图的边列表表示
    vector<Edge> edges =
        {
            {0, 1, -1},
            {0, 2, 4},
            {1, 2, 3},
            {1, 3, 2},
            {1, 4, 2},
            {3, 2, 5},
            {3, 1, 1},
            {4, 3, -3}};

    int numVertices = 5; // 顶点数量
    int source = 0;      // 源点
    bellmanFord(edges, numVertices, source);

    return 0;
}