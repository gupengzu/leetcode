#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    static bool cmp(const int&x,const int&y)
    {
        string a = to_string(x);
        string b = to_string(y);
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for(auto &num:nums)
        {
            ans += to_string(num);
        }
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};