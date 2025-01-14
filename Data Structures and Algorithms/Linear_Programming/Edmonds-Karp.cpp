#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(vector<vector<int>>&residualGraph,int source,int sink,vector<int>&parent)
{
    int V = residualGraph.size();
    vector<bool> isvisited(V, false);
    queue<int> q;
    isvisited[source] = true;
    parent[source] = -1;
    q.push(source);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
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

int EdmondsKarp(vector<vector<int>>&graph,int source,int sink)
{
    vector<vector<int>> residualGraph = graph;
    int V = residualGraph.size();
    vector<int> parent(V);
    int maxFlow = 0;

    while(bfs(residualGraph,source,sink,parent))
    {
        int pathFlow = INT_MAX;
        for (int v = sink; v != source;v=parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        maxFlow += pathFlow;
        for (int v = sink; v != source;v=parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
    }
    return maxFlow;
}

void findReachableVertices(vector<vector<int>>&residualGraph,int source,vector<bool>&isvisited)
{
    int V = residualGraph.size();
    queue<int> q;
    q.push(source);
    isvisited[source] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < V;i++)
        {
            if(!isvisited[i]&&residualGraph[u][i]>0)
            {
                isvisited[i] = true;
                q.push(i);
            }
        }
    }
}

void findMinCut(vector<vector<int>>& graph,int source,int sink)
{
    int V = graph.size();
    vector<vector<int>> residualGraph = graph;
    vector<int> parent(V);

    int maxflow = EdmondsKarp(graph, source, sink);

    vector<bool> isvisited(V, false);
    findReachableVertices(residualGraph, source, isvisited);

    cout << "The edges in the minimum cut are:" << endl;
    for (int u = 0; u < V;u++)
    {
        cout << 111 << endl;
        for (int v = 0; v < V;v++)
        {
            cout << 22 << endl;
            if(isvisited[u]&&!isvisited[v]&&graph[u][v]>0)
            {
                cout << 33 << endl;
                cout << u << " - " << v << endl; 
            }
        }
    }
}

int main()
{
    vector<vector<int>> graph = 
    {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;

    cout << "The maximum possible flow is " << EdmondsKarp(graph, source, sink) << endl;
    findMinCut(graph, source, sink);
    return 0;
}