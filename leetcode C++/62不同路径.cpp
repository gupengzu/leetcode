#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsMain(int m,int n,vector<vector<int>>&remember)
    {
        if(m==1||n==1)
        {
            return 1;
        }
        else if(remember[m][n]!=0)
        {
            return remember[m][n];
        }
        int now = uniquePathsMain(m - 1, n, remember) + uniquePathsMain(m, n - 1, remember);
        remember[m][n] = now;
        return now;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> remember(m+1 ,vector<int>(n+1,0));
        return uniquePathsMain(m, n, remember);
    }
};