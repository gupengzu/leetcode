#include<iostream>
#include<string.h>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int>result;
        int m_size = nums.size();
        for (int i = 0; i < m_size-1; i++)
        {
            for (int j = i + 1; j < m_size; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};