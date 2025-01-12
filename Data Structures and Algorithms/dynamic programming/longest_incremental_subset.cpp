#include<iostream>
#include<vector>
using namespace std;

int DP(int last,int now,vector<int>original_set,vector<vector<int>>&length_of_DP)
{
    int length = original_set.size();
    if(now==length)
    {
        return 0;
    }
    else if(original_set[now]<original_set[last])
    {
        return DP(last, now + 1, original_set,length_of_DP);
    }
    else
    {
        if(length_of_DP[last][now]!=INT_MAX)
        {
            return length_of_DP[last][now];
        }
        else
        {
            length_of_DP[last][now]= max(DP(last, now + 1, original_set, length_of_DP), 1+DP(now, now + 1, original_set, length_of_DP));
            return length_of_DP[last][now];
        }
    }
}

int longset_subset(vector<int>original_set)
{
    original_set.insert(original_set.begin(), INT_MIN);
    vector<vector<int>> length_of_DP(original_set.size(),vector<int>(original_set.size(),INT_MAX));

    return DP(0, 1, original_set,length_of_DP);
}

int main() 
{
    vector<int> original_set = {1, 2, 3, 4, 5,1};
    int result = longset_subset(original_set);

    // 输出结果
    cout << "Result: " << result << endl;

    return 0;
}