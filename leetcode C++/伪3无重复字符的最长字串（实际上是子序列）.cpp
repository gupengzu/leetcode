#include<iostream>
#include<string.h>
#include<set>
#include<list>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        int len = s.size();
        int result = 1;
        for (int i = 1; i < len; i++)
        {
            int temp = 0;
            for (int j = 0; j < i; j++)
            {
                if (s[i] != s[j])
                {
                    temp += 1;
                }
                if (temp == i)
                {
                    result += 1;
                }
            }
        }
        return result;
    }
};

int main()
{
    string s = "pwwkew";
    Solution solu1;
    int b = solu1.lengthOfLongestSubstring(s);
    cout << b << endl;
    return 0;
}