#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Dinic
{
public:
    Dinic(int n)
    {
        this->n = n;
        this->level.resize(n);
        this->adj.resize(n);
    }
    void addEdge(int u, int v, int capacity)
    {
        adj[u].push_back(edges.size());
        edges.push_back({u, v, capacity, 0});
        adj[v].push_back(edges.size());
        edges.push_back({v, u, 0, 0});
    }

    int maxflow(int source, int sink)
    {
        int flow = 0;
        while (bfs(source, sink))
        {
            while (int pushed = dfs(source, sink, INT_MAX))
            {
                flow += pushed;
            }
        }
        return flow;
    }

private:
    int n; // number of vectices
    int source;
    int sink;
    struct Edge
    {
        int u, v, capacity, flow;
    };
    vector<Edge> edges;
    vector<int> level;
    vector<vector<int>> adj;

    bool bfs(int source, int sink)
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(source);
        level[source] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int id : adj[u])
            {
                Edge &e = edges[id];
                if (e.capacity > e.flow && level[e.v] == -1)
                {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[sink] != -1;
    }

    bool dfs(int u, int sink, int pushed)
    {
        if (pushed <= 0)
        {
            return 0;
        }
        if (u == sink)
        {
            return pushed;
        }
        for (int i = 0; i < adj[u].size(); i++)
        {
            int id = adj[u][i];
            Edge &e = edges[id];
            if (level[u] + 1 != level[e.v] || e.capacity <= e.flow)
            {
                continue;
            }
            int tr = dfs(e.v, sink, min(pushed, e.capacity - e.flow));
            if (tr <= 0)
            {
                continue;
            }

            e.flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
};

int main()
{
    int n = 6; // Number of vertices
    Dinic dinic(n);

    // Add edges
    dinic.addEdge(0, 1, 16);
    dinic.addEdge(0, 2, 13);
    dinic.addEdge(1, 2, 10);
    dinic.addEdge(1, 3, 12);
    dinic.addEdge(2, 1, 4);
    dinic.addEdge(2, 4, 14);
    dinic.addEdge(3, 2, 9);
    dinic.addEdge(3, 5, 20);
    dinic.addEdge(4, 3, 7);
    dinic.addEdge(4, 5, 4);

    int source = 0;
    int sink = 5;

    cout << "The maximum possible flow is " << dinic.maxflow(source, sink) << endl;

    return 0;
}