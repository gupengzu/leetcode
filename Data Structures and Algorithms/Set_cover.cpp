#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//函数用于找到集合覆盖
vector<int> setCover(vector<unordered_set<int>> &sets,unordered_set<int>&universe)
{
    vector<int> result;
    unordered_set<int> covered;

    while(covered!=universe)
    {
        int bestSet = -1;
        int maxElement = 0;
        for(int i=0;i<sets.size();++i)
        {
            unordered_set<int> temp;
            for(int element:sets[i])
            {
                if(universe.count(element)&&!covered.count(element))
                {
                    temp.insert(element);
                }
            }
            if(temp.size()>maxElement)
            {
                maxElement=temp.size();
                bestSet=i;
            }
        }

        if(bestSet==-1)
        {
            break;
        }

        result.push_back(bestSet);
        for(int element:sets[bestSet])
        {
            covered.insert(element);
        }
    }

    return result;
}


int main()
{   
    vector<unordered_set<int>> sets = {
        {1, 2, 3},
        {2, 4},
        {3, 4},
        {4, 5}
    };


    unordered_set<int> universe = {1, 2, 3, 4, 5};
    vector<int> result = setCover(sets, universe);
    cout << "集合覆盖的集合索引：";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}