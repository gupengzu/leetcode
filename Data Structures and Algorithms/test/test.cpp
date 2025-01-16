#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(vector<vector<int>>&residualGraph,int source,int sink,vector<int>&parent)
{
    int V = residualGraph.size();
    vector<bool> isvisited(V, false);
    queue<int> q;
    q.push(source);
    isvisited[source] = true;
    parent[source] = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V;v++)
        {
            if(!isvisited[v]&&residualGraph[u][v]>0)
            {
                if(v==sink)
                {
                    parent[v] = u;
                    return true;
                }
                else
                {
                    isvisited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

int maxFlow(vector<vector<int>>&graph,int source,int sink)
{
    int V = graph.size();
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(V);

    int maxflow = 0;
    while(bfs(residualGraph,source,sink,parent))
    {
        int newflow = INT_MAX;
        for (int v = sink; v != source;v=parent[v])
        {
            newflow = min(newflow, residualGraph[parent[v]][v]);
        }
        for (int v = sink; v != source;v=parent[v])
        {
            residualGraph[parent[v]][v] -= newflow;
            residualGraph[v][parent[v]] += newflow;
        }
        maxflow += newflow;
    }
    return maxflow;
}

int main()
{
        // 定义一个示例图的邻接矩阵
    vector<vector<int>> graph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;

    // 计算最大流并输出结果
    cout << "The maximum possible flow is " << maxFlow(graph, source, sink) << endl;
    return 0;
}