// #include<iostream>
// #include<vector>
// using namespace std;

// class Graph
// {
//     int v;//顶点的数量
//     vector<vector<int>> adj; // 邻接表

// public:
//     //constructor
//     Graph(int v);
//     //add edge
//     void addEdge(int v, int w);
//     //DFS(Depth First Search)
//     void DFS(int v);
//     //helper function(for DFS)
//     void DFSUtil(int v, vector<bool> &visited);
// };

// Graph::Graph(int v)
// {
//     this->v = v;
//     adj.resize(v);
// }

// void Graph::addEdge(int v,int w)
// {
//     adj[v].push_back(w);
// }

// void Graph::DFSUtil(int v,vector<bool>&visited)
// {
//     //mark the current node as visited
//     visited[v] = true;
//     cout << v << " ";
//     //recursively visit all adjacent nodes
//     for(int edge:adj[v])
//     {
//         if(!visited[edge])
//         {
//             DFSUtil(edge, visited);
//         }
//     }
// }

// void Graph::DFS(int v)
// {
//     //initialize all nodes as unvisited
//     vector<bool>visited(v,false);
//     //call the helper function
//     DFSUtil(v, visited);
// }

// int main()
// {
//     Graph g(4);
//     g.addEdge(0,1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 0);
//     g.addEdge(2, 3);
//     g.addEdge(3, 3);

//     cout << "DFS from point 2" << endl;
//     g.DFS(2);
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    int vertexs;                // vertexs
    vector<vector<int>> adj; // adjacency list
public:
    //constructor
    Graph(int number_of_vertexs);
    //add edge function
    void addEdge(int source_point, int direction_point);
    //depth first search
    void DFS(int number_of_vertexs,int start_point);
    //helper function for DFS
    void DFSUtil(vector<bool> isvisited,int the_current_point);
};

Graph::Graph(int number_of_vertexs)
{
    this->vertexs = number_of_vertexs;
    adj.resize(number_of_vertexs);
}

void Graph::addEdge(int source_point,int direction_point)
{
    adj[source_point].push_back(direction_point);
}

void Graph::DFSUtil(vector<bool>isvisited,int the_current_point)
{
    isvisited[the_current_point]=true;
    cout << the_current_point << " " ;
    for(int point:adj[the_current_point])
    {
        if(!isvisited[point])
        {
            DFSUtil(isvisited, point);
        }
    }
}

void Graph::DFS(int number_of_vertexs,int start_point)
{
    vector<bool> isvisited(number_of_vertexs, false);
    DFSUtil(isvisited, start_point);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(4, 2);
    return 0;
}