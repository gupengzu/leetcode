#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int>> graph;

void BFS(int start)
{
    int n=graph.size();
    // 记录顶点是否被访问过
    vector<bool> visited(n, false);
    //记录从起点到各顶点的距离
    vector<int> distance(n, -1);
    //初始化起点
    visited[start] = true;
    distance[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        //遍历u的所有邻接顶点
        for(int v:graph[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                distance[v]=distance[u]+1;
                q.push(v);
            }
        }
    }
    for (int i = 0;i<n;i++)
    {
        cout<<"distance from"<<start<<"to"<<i<<"is"<<distance[i]<<endl;
    }
}


int main()
{
    // int n,m;
    // cin>>n>>m;
    // graph.resize(n);
    // for(int i=0;i<m;i++)
    // {
    //     int u,v;
    //     cin>>u>>v;
    //     graph[u].push_back(v);
    //     graph[v].push_back(u);
    // }
    BFS(0);

    return 0;
}