#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int start = 0;
        int end = 0;
        int profit = 0;
        while((end+1)<prices.size())
        {
            if(prices[end+1]>=prices[end])
            {
                end += 1;
            }
            else
            {
                profit += prices[end] - prices[start];
                end = end + 1;
                start = end;
            }
        }
        profit += prices[end] - prices[start];
        return profit;
    }
};