#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<pair<int,int>>> reverseGraph(vector<vector<pair<int,int>>>graph)
{
    vector<vector<pair<int, int>>> rev_graph;
    rev_graph.resize(graph.size());
    for (int i = 0; i < graph.size();i++)
    {
        for(pair<int,int>edge:graph[i])
        {
            int end=edge.first;
            int weight=edge.second;
            rev_graph[end].push_back({i, weight});
        }
    }
    return rev_graph;
}

int shortLength_A_to_B_main(vector<vector<pair<int,int>>>regraph,int start_point,int end_point,vector<int>&shortestLength,vector<int>&choices)
{
    if(start_point==end_point)
    {
        return 0;
    }
    else if (regraph[end_point].empty())
    {
        return INT_MAX;
    }
    else if(shortestLength[end_point]!=-1)
    {
        return shortestLength[end_point];
    }
    else
    {
        int min_length = INT_MAX;
        for(pair<int,int>edge:regraph[end_point])
        {
            int prepoint = edge.first;
            int weight=edge.second;
            int length_start_to_prepoint = shortLength_A_to_B_main(regraph, start_point, prepoint, shortestLength,choices);
            if(length_start_to_prepoint!=INT_MAX)
            {
                if(length_start_to_prepoint+weight<min_length)
                {
                    min_length = length_start_to_prepoint + weight;
                    choices[end_point] = prepoint;
                }
            }
        }
        shortestLength[end_point] = min_length;
        return min_length;
    }
}

int shortestLength_from_A_to_B(vector<vector<pair<int,int>>>graph,int start_point,int end_point)
{
    vector<int> shortestLength(graph.size(), -1);
    shortestLength[start_point] = 0;
    vector<int> choices(graph.size(), -1);
    int distance = shortLength_A_to_B_main(reverseGraph(graph), start_point, end_point, shortestLength,choices);

    if(distance==INT_MAX)
    {
        cout << "there is no way from start_point to end_point." << endl;
    }
    else
    {
        vector<int> points_in_the_way;
        int at = end_point;
        while(at!=start_point)
        {
            points_in_the_way.push_back(at);
            at = choices[at];
        }
        points_in_the_way.push_back(start_point);
        reverse(points_in_the_way.begin(), points_in_the_way.end());

        cout << "The shortest path from " << start_point << " to " << end_point << " is: ";
        for (int point : points_in_the_way) {
            cout << point << " ";
        }
        cout << endl;

    }

    return distance;
}

int main() {
    // 示例图的邻接表表示
    vector<vector<pair<int, int>>> graph = {
        {{1, 3}, {2, 1}},
        {{3, 7}},
        {{3, 11}},
        {}
    };

    int start_point = 0; // 起始点
    int end_point = 3;   // 终点

    int shortest_length = shortestLength_from_A_to_B(graph, start_point, end_point);
    if (shortest_length == INT_MAX) {
        cout << "There is no path from " << start_point << " to " << end_point << endl;
    } else {
        cout << "The shortest path from " << start_point << " to " << end_point << " is " << shortest_length << endl;
    }

    return 0;
}