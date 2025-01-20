#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool first_match(string s, string p, int i, int j)
    {
        return (s[i] == p[j] || p[j] == '.');
    }
    bool isMatch(string s, string p)
    {

        vector<vector<bool>> isSame(s.size() + 1, vector<bool>(p.size()+1, false));
        isSame[0][0] = true;
        for (int y = 2; y <= p.size(); y++)
        {
            if (p[y-1] == '*')
            {
                isSame[0][y] = isSame[0][y - 2];
            }
        }

        for (int x = 0; x < s.size(); x++)
        {
            for (int y = 0; y < p.size(); y++)
            {
                if (p[y] == '*')
                {
                    isSame[x + 1][y + 1] = (isSame[x + 1][y - 1] || (first_match(s, p, x, y - 1) && isSame[x][y + 1]));
                }
                else
                {
                    isSame[x + 1][y + 1] = (first_match(s, p, x, y) && isSame[x][y]);
                }
            }
        }
        return isSame[s.size()][p.size()];
    }
};