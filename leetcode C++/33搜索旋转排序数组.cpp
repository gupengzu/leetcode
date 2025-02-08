#include<iostream>
#include<vector>
using namespace std;

//超时答案
// class Solution 
// {
// public:
//     int search(vector<int>& nums, int target) 
//     {
//         int left_point = 0;
//         int right_point = nums.size() - 1;

//         while (left_point<=right_point)
//         {
//             int mid_point = left_point+(right_point-left_point) / 2;
            
//             if(nums[mid_point]==target)
//             {
//                 return mid_point;
//             }
//             else if(nums[mid_point]>target&&nums[mid_point]<nums[right_point])
//             {
//                 //target一定在0到nums[mid_point]之间
//                 right_point = mid_point - 1;
//             }
//             else if(nums[mid_point]<target&&nums[mid_point]>nums[right_point])
//             {
//                 //target一定在nums[mid_point]到最大值之间
//                 left_point = mid_point + 1;
//             }
//             else if(nums[mid_point]>target&&nums[mid_point]>nums[right_point])
//             {
//                 //mid_point现在一定在最大值左侧，但是不确定target在最大值左侧还是最大值右侧
//                 if(target>nums[right_point])
//                 {
//                     //target在最大值左侧，且在mid_point左侧
//                     right_point = mid_point - 1;
//                 }
//                 else
//                 {
//                     //target在最大值右侧，且在mid_point右侧
//                     left_point = mid_point + 1;
//                 }
//             }
//             else if(nums[mid_point]<target&&nums[mid_point]<nums[right_point])
//             {
//                 //mid_point一定在最大值右侧
//                 if(target>nums[right_point])
//                 {
//                     //target在最大值左侧
//                     right_point = mid_point - 1;
//                 }
//                 else
//                 {
//                     left_point = mid_point + 1;
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size()==1)
        {
            return nums[0] == target ? 0: -1;
        }
        int left_point = 0;
        int right_point = nums.size() - 1;
        int mid_point;
        while ((right_point-left_point)!=1)
        {
            mid_point = (left_point + right_point) / 2;
            if(nums[mid_point]>nums[left_point])
            {
                left_point = mid_point;
            }
            else if(nums[mid_point]<nums[right_point])
            {
                right_point = mid_point;
            }
        }
        if(target<=nums[left_point])
        {
            int left = 0;
            int right = left_point;
            while (left<=right)
            {
                mid_point = left + (right - left) / 2;
                if(nums[mid_point]==target)
                {
                    return mid_point;
                }
                else if(nums[mid_point]<target)
                {
                    left = mid_point + 1;
                }
                else
                {
                    right = mid_point - 1;
                }
            }
        }
        if(target>=nums[right_point])
        {
            int left = right_point;
            int right = nums.size() - 1;
            while (left<=right)
            {
                mid_point = left + (right - left) / 2;
                if(nums[mid_point]==target)
                {
                    return mid_point;
                }
                else if(nums[mid_point]<target)
                {
                    left = mid_point + 1;
                }
                else
                {
                    right = mid_point - 1;
                }
            }
        }
        return -1;
    }
};