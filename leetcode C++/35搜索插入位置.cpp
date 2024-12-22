#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.size() == 0)
        {
            nums.push_back(target);
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] < target)
            {
                left =mid+1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        nums.insert(nums.begin() + left, target);
        return left;
    }
};