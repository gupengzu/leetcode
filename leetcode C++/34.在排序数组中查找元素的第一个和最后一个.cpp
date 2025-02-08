#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> result;
        result.push_back(-1);
        result.push_back(-1);
        int left_point = 0;
        int right_point = nums.size() - 1;
        int mid = -1;
        while (left_point<=right_point)
        {
            mid = left_point + (right_point - left_point) / 2;
            if(nums[mid]==target)
            {
                result[0] = mid;
                result[1] = mid;
                change_start_and_end(nums, result, target);
                break;
            }
            else if(nums[mid]>target)
            {
                right_point = mid - 1;
            }
            else
            {
                left_point = mid + 1;
            }
        }
        return result;
    }
    void change_start_and_end(vector<int>&nums,vector<int>&result,int target)
    {
        int start_index_of_same_as_target = result[0];
        int end_index_of_same_as_target = result[1];
        while (start_index_of_same_as_target>=0&&nums[start_index_of_same_as_target]==target)
        {
            start_index_of_same_as_target -= 1;
        }
        start_index_of_same_as_target += 1;
        while (end_index_of_same_as_target<=nums.size()-1&&nums[end_index_of_same_as_target]==target)
        {
            end_index_of_same_as_target += 1;
        }
        end_index_of_same_as_target -= 1;
        result[0] = start_index_of_same_as_target;
        result[1] = end_index_of_same_as_target;
    }
};