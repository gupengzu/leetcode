#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 边的结构体
struct Edge
{
    int dest;
    int weight;
};

//使用优先队列的Prim算法实现
vector<Edge>Prim(vector<vector<Edge>>graph,int numVertices)//输入存储边的容器，并输入点的个数
{
    vector<Edge> mst;//用以存储最终的最小生成树
    vector<bool> in_mst(numVertices, false);//记录该点是否在最小生成树
    vector<int> key(numVertices, INT_MAX);//记录每个顶点的最小权重
    vector<int> parents(numVertices, -1);//记录每个顶点的父节点

    //优先队列，存储（权重，顶点）对
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //priority_queue是一个容器适配器，第一个参数代表存储的数据类型（此处为（权重，顶点）对），
    //第二个参数代表用什么样的容器存储数据，vector是一种动态大小的数组容器，
    //第三个参数是定义优先级比较规则，此处的greater会先比较容器中所有pair对的第一个元素的大小，然后比较第二个
    key[0] = 0;
    pq.push({0, 0});

    while(!pq.empty())
    {
        int u = pq.top().second;//pq.top()用来取到pq优先队列中优先级最高的那个pair，second取到pair中的第二个元素，即顶点
        pq.pop();//优先队列保证队列中首个元素是优先级最高的，所以此处是将优先级最高的元素踢出队列

        if(in_mst[u])
        {
            continue;//如果u已经在最小生成树中，则可以直接结束本次关于u的循环
        }
        in_mst[u] = true;//如果u不在最小生成树，先将其加入最小生成树（因为这是目前检查到的可以从最小生成树中接触到的路程最小的点）
        //然后更新该点可以接触到的点
        for(const Edge&edge:graph[u])
        {
            int v = edge.dest;//v(vertice)代表edge将接触到的点
            int weight = edge.weight;//weight代表edge的权重
            if(!in_mst[v]&&(weight<key[v]))//如果v没在mst中且该边的权重小于更新前mst到达v的最小权重
            {
                key[v] = weight;
                pq.push({key[v], v});
                parents[v] = u;
            }
        }
    }

    //构建最小生成树
    for (int i = 1; i < numVertices;++i)//从1开始是因为在上面已经将最小生成树的起点{0，0}加入
    {
        if(parents[i]!=-1)
        {
            mst.push_back({parents[i], key[i]});
        }
    }
    return mst;
}

int main() {
     // 示例图的邻接表表示
    vector<vector<Edge>> graph = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {3, 8}, {4, 5}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}, {4, 9}},
        {{1, 5}, {2, 7}, {3, 9}}
    };

    int numVertices = 5; // 顶点数量

    vector<Edge> mst = Prim(graph, numVertices);

    // 输出最小生成树的边
    cout << "最小生成树的边:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.dest << " -- " << edge.weight << endl;
    }

    return 0;
}