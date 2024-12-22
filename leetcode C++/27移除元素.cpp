#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        vector<int>temp;
        for (int element : nums)
        {
            if (element != val)
            {
                temp.push_back(element);
            }
        }
        nums.resize(temp.size());
        int index = 0;
        for (int element : temp)
        {
            nums[index++] = element;
        }
        return index;
    }
};