// #include<iostream>
// #include<climits>
// #include<vector>
// using namespace std;

// int  fibonacc_recursion(int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     return fibonacc_recursion(n - 1) + fibonacc_recursion(n - 2);
// }

// int main()
// {
//     int number = fibonacc_recursion(8);
//     cout << number << endl;
// }

// int fibonacc_iteration(int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     int a = 0;
//     int b = 1;
//     for (int i = 2; i < n;i++)
//     {
//         int temp = a + b;
//         a = b;
//         b = temp;
//     }
//     return a + b;
// }

// int main()
// {
//     int number = fibonacc_iteration(8);
//     cout << number << endl;
// }

// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// //Bian
// void BFS(vector<vector<int>> graph,int start_point,int number_of_points)
// {
//    vector<bool>isvisited(number_of_points,false);
//    queue<int> queue_of_points;
//    queue_of_points.push(start_point);
//    isvisited[start_point] = true;
//    while(!queue_of_points.empty())
//    {
//     int current_point=queue_of_points.front();
//     queue_of_points.pop();
//     cout << current_point << " ";
//     for(int point:graph[current_point])
//     {
//         if(!isvisited[point])
//         {
//             queue_of_points.push(point);
//             isvisited[point] = true;
//         }
//     }
//    }
// }

// int main()
// {
//     // 示例图的邻接表表示
//     vector<vector<int>> graph = {
//         {1, 2},
//         {0, 3, 4},
//         {0, 4},
//         {1, 5},
//         {1, 2, 5},
//         {3, 4}
//     };
//     int the_size_of_graph = graph.size();
//     int start_point = 0;
//     cout << "BFS traversal starting from vertex" << start_point << endl;
//     BFS(graph, start_point,the_size_of_graph);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<queue>
// #include<utility>
// using namespace std;

// void Dijkstra_algorithm(vector<vector<pair<int,int>>>graph,int start_point)
// {
//     int size_of_graph=graph.size();
//     vector<int> the_shortest_length(size_of_graph, INT_MAX);
//     vector<bool> is_in_mst(size_of_graph, false);
//     the_shortest_length[start_point] = 0;
//     //priority_queue to store(distance,vertex)pairs
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
//     pq.push({0, start_point});
//     while(!pq.empty())
//     {
//         int current_point = pq.top().second;
//         pq.pop();

//         if(is_in_mst[current_point])continue;
//         is_in_mst[current_point] = true;
//         for(pair<int,int>edge:graph[current_point])
//         {
//             int direction_vertex=edge.first;
//             int weight = edge.second;
//             int new_length_to_direction_vertex = weight + the_shortest_length[current_point];
//             if(!is_in_mst[direction_vertex] && new_length_to_direction_vertex < the_shortest_length[direction_vertex])
//             {
//                 pq.push({new_length_to_direction_vertex, direction_vertex});
//                 the_shortest_length[direction_vertex] = new_length_to_direction_vertex;
//             }
//         }
//     }
//     for(int i=0;i<size_of_graph;i++)
//     {
//         cout << "from " << start_point << " to " << i << " is " << the_shortest_length[i] << endl;
//     }
// }

// int main()
// {
//     // 示例图的邻接表表示
//     vector<vector<pair<int, int>>> graph = {
//         {{1, 2}, {2, 4}},
//         {{2, 1}, {3, 7}},
//         {{3, 3}},
//         {{4, 1}},
//         {}
//     };
//     Dijkstra_algorithm(graph, 0);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// using namespace std;

// void Ballman_Ford_Algorithm(vector<vector<pair<int,int>>>graph,int start_vertex)
// {
//     int size_of_graph = graph.size();
//     bool is_update = true;
//     int total_times_of_update = 0;
//     vector<int> the_shortest_length(size_of_graph, INT_MAX);
//     the_shortest_length[start_vertex] = 0;
//     while(is_update)
//     {
//         is_update = false;
//         for(int i=0;i<size_of_graph;i++)
//         {
//             if(the_shortest_length[i]!=INT_MAX)
//             {
//                 for(pair<int,int>edge : graph[i])
//                 {
//                     int destination=edge.first;
//                     int weight=edge.second;
//                     int new_length_to_destination = weight + the_shortest_length[i];
//                     if(new_length_to_destination < the_shortest_length[edge.first])
//                     {
//                         is_update=true;
//                         the_shortest_length[edge.first] = new_length_to_destination;
//                     }
//                 }
//             }
//         }
//         total_times_of_update += 1;
//         if(total_times_of_update > size_of_graph)
//         {
//             cout << "there has negative cycle." << endl;
//             return;
//         }
//     }

//    for(int i=0;i<size_of_graph;i++)
//    {
//        cout << "from " << start_vertex << " to " << i << " is " << the_shortest_length[i] << endl;
//    }
// }

// int main()
// {
//     // 示例图的邻接表表示
//     vector<vector<pair<int, int>>> graph = {
//         {{1, 2}, {2, 4}},
//         {{2, 1}, {3, 7}},
//         {{3, 3}},
//         {{4, 1}},
//         {}
//     };
//     Ballman_Ford_Algorithm(graph, 0);
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// struct Edge
// {
//     int source_point;
//     int direction;
//     int weight;
// };

// struct Union_find
// {
//     vector<int> father;
//     vector<int> rank;

//     Union_find(int n)
//     {
//         rank.resize(n, 0);
//         father.resize(n);
//         for (int i = 0; i < n;i++)
//         {
//             father[i] = i;
//         }
//     }

//     int find_father(int n)
//     {
//         return father[n] == n ? n : find_father(father[n]);
//     }

//     void union_roots(int x,int y)
//     {
//         int x_father=find_father(x);
//         int y_father = find_father(y);
//         if(x_father==y_father)
//         {
//             return;
//         }
//         else
//         {
//             if(rank[x_father]<rank[y_father])
//             {
//                 father[x_father] = y_father;
//             }
//             else if(rank[x_father]>rank[y_father])
//             {
//                 father[y_father] = x_father;
//             }
//             else
//             {
//                 rank[y_father]++;
//                 father[x_father] = y_father;
//             }
//         }
//     }
// };

// vector<Edge>Kruskal_Algorithm(vector<Edge>edges,int number_of_points)
// {
//     Union_find uf(number_of_points);
//     vector<Edge> mst;
//     sort(edges.begin(), edges.end(), [](Edge a, Edge b)
//          { return a.weight < b.weight; });
//     for(Edge edge:edges)
//     {
//         int father_source=uf.find_father(edge.source_point);
//         int father_direction = uf.find_father(edge.direction);
//         if(father_source!=father_direction)
//         {
//             uf.union_roots(edge.source_point, edge.direction);
//             mst.push_back(edge);
//         }
//     }
//     return mst;
// }

// int main()
// {
//     // cout << "test" << endl;
//     //  示例图的边列表表示
//     vector<Edge> edges = {
//         {0, 1, 10},
//         {0, 2, 6},
//         {0, 3, 5},
//         {1, 3, 15},
//         {2, 3, 4}};

//     int numVertices = 4; // 顶点数量

//     vector<Edge> mst = Kruskal_Algorithm(edges, numVertices);

//     // 输出最小生成树的边
//     cout << "最小生成树的边:" << endl;
//     for (const Edge &edge : mst)
//     {
//         cout << edge.source_point << " -- " << edge.direction << " == " << edge.weight << endl;
//     }

//     return 0;
// }

// #include <queue>
// #include <iostream>
// #include <vector>
// using namespace std;

// struct Edge
// {
//     int end;
//     int weight;
// };

// vector<Edge> Prim_Algorithm(vector<vector<Edge>> graph, int number_of_points)
// {
//     vector<Edge> mst;
//     vector<int> key(number_of_points, INT_MAX);
//     vector<bool> is_in_mst(number_of_points, false);
//     vector<int> father_of_points(number_of_points, -1);
//     // store (point,cost)
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     key[0] = 0;
//     pq.push({0, 0});

//     while (!pq.empty())
//     {
//         int current_point = pq.top().first;

//         pq.pop();

//         if (is_in_mst[current_point])
//             continue;
//         is_in_mst[current_point] = true;

//         for (Edge edge : graph[current_point])
//         {
//             if (!is_in_mst[edge.end] && edge.weight < key[edge.end])
//             {
//                 father_of_points[edge.end] = current_point;
//                 key[edge.end] = edge.weight;
//                 pq.push({edge.end, key[edge.end]});
//             }
//         }
//     }

//     for (int i = 1; i < number_of_points; i++)
//     {
//         if (father_of_points[i] != -1)
//         {
//             mst.push_back({father_of_points[i], key[i]});
//         }
//     }
//     return mst;
// }

// int main()
// {
//     // 示例图的邻接表表示
//     vector<vector<Edge>> graph = {
//         {{1, 2}, {3, 6}},
//         {{0, 2}, {2, 3}, {3, 8}, {4, 5}},
//         {{1, 3}, {4, 7}},
//         {{0, 6}, {1, 8}, {4, 9}},
//         {{1, 5}, {2, 7}, {3, 9}}};

//     int numVertices = 5; // 顶点数量

//     vector<Edge> mst = Prim_Algorithm(graph, numVertices);

//     // 输出最小生成树的边
//     cout << "最小生成树的边:" << endl;
//     for (const Edge &edge : mst)
//     {
//         cout << edge.end << " -- " << edge.weight << endl;
//     }

//     return 0;
// }
