#include<iostream>
#include<vector>
using namespace std;

//此答案超出内存限制
// class Solution 
// {
// public:
//     int maxSubArray(vector<int>& nums) 
//     {
//         int max = max_of_all_menus(nums);
//         if(max<0)
//         {
//             return max;
//         }
//         return max_subarray(nums);
//     }
//     int max_subarray(vector<int>nums)
//     {
//         if(nums.size()==0)
//         {
//             return 0;
//         }
//         int result = 0;
//         int first = nums[0];
//         nums.erase(nums.begin());
//         result = max(max_subarray(nums), (first + after_choose_first(nums)));
//         return result;
//     }
//     int after_choose_first(vector<int>nums)
//     {
//         if(nums.size()==0)
//         {
//             return 0;
//         }
//         int first = nums[0];
//         nums.erase(nums.begin());
//         return max(0,(first+after_choose_first(nums)));
//     }
//     int max_of_all_menus(vector<int>&nums)
//     {
//         int max = INT_MIN;
//         for (int i = 0; i < nums.size();i++)
//         {
//             if(nums[i]>max)
//             {
//                 max = nums[i];
//             }
//         }
//         return max;
//     }
// };



class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size();i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};