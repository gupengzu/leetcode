#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int len = nums.size();

        for (int i = 0; i < len - 2; i++)
        {
            int left = i + 1, right = len - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closest - target))
                {
                    closest = sum;
                }
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    return sum;
                }
            }
        }
        return closest;
    }
};

//int main()
//{
//    Solution sol;
//    vector<int> nums = {-1, 2, 1, -4};
//    int target = 1;
//    cout << sol.threeSumClosest(nums, target) << endl;
//    return 0;
//}