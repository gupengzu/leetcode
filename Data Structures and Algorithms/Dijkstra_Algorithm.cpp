#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// 表示无穷大，用于初始化距离
const int INF = INT_MAX;

// 迪杰斯特拉算法实现
void Dijkstra(vector<vector<int>> &graph, int source)
{
    int n = graph.size();
    vector<int> dist(n, INF); // 距离数组，初始化为无穷大
    dist[source] = 0;         // 起点到自己的距离为0

    // 优先队列，存储（距离，顶点）对
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // 遍历所有邻接顶点
        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != 0 && dist[v] > dist[u] + graph[u][v])
            {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    // 输出最短路径
    cout << "顶点" << source << "到其他顶点的最短路径距离" << endl;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
        {
            cout << "顶点" << i << "不可到达" << endl;
        }
        else
        {
            cout << "到顶点" << i << "的距离为" << dist[i] << endl;
        }
    }
}
int main()
{
    // 示例图的邻接矩阵表示
    vector<vector<int>> graph = {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 0, 50, 10, 0},
        {20, 0, 0, 20, 33, 0},
        {0, 50, 20, 0, 20, 2},
        {0, 10, 33, 20, 0, 1},
        {0, 0, 0, 2, 1, 0}};

    int source = 0; // 源点
    Dijkstra(graph, source);

    return 0;
}