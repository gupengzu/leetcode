#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        set<int>temp;
        int m_size = nums.size();
        for (int element : nums)
        {
            temp.insert(element);
        }
        int index = 0;
        for (int element : temp)
        {
            nums[index++] = element;
        }
        return index;
    }
};