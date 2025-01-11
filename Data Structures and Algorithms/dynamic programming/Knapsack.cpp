#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int kanpsack_main(int order,int most_weight_now,vector<pair<int,int>>things,vector<vector<int>>&now)
{
    if(order==things.size()||most_weight_now<=0)
    {
        return 0;
    }
    if(now[order][most_weight_now]!=-1)
    {
        return now[order][most_weight_now];
    }
    if(things[order].first>most_weight_now)
    {
        return kanpsack_main(order + 1, most_weight_now, things, now);
    }
    else
    {
        int choose_this = things[order].second + kanpsack_main(order + 1, most_weight_now - things[order].first, things, now);
        int not_choose_this = kanpsack_main(order + 1, most_weight_now, things, now);
        now[order][most_weight_now] = max(choose_this, not_choose_this);
        return now[order][most_weight_now];
    }
}

int knapsack(vector<pair<int,int>>things,int most_weight)//pair<weight,value>
{
    int size_of_things = things.size();
    vector<vector<int>> now(size_of_things, vector<int>(most_weight+1,-1));
    return kanpsack_main(0,most_weight,things,now);
}

int main() {
    vector<pair<int, int>> things = {{2, 3}, {3, 4}, {4, 5}, {5, 6}};
    int most_weight = 5;
    int max_value = knapsack(things, most_weight);
    cout << "The maximum value that can be obtained is: " << max_value << endl;
    return 0;
}