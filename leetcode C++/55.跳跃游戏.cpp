#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int Now = 0;
        int Max = Now + nums[Now];
        while (true)
        {
            if (Max >= nums.size() - 1)
            {
                return true;
            }
            int Max_last_time = Max;
            for (int i = Now; i <= Max_last_time; i++)
            {
                Max = max(Max, i + nums[i]);
            }
            if (Max_last_time == Max)
            {
                return false;
            }
        }
    }
};