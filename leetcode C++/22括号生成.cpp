#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(n, result, 0, 0, "");
        return result;
    }
    void backtrack(int n, vector<string> &result, int left, int right, string now)
    {
        if (right > left)
        {
            return;
        }
        if (right == n && left == n)
        {
            result.push_back(now);
        }
        if (left < n)
        {
            backtrack(n, result, left + 1, right, now + "(");
        }
        if (right < left)
        {
            backtrack(n, result, left, right + 1, now + ")");
        }
    }
};