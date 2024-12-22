#include<iostream>
#include<string.h>
#include<set>
#include<list>
using namespace std;

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
        if (len == 0)
        {
            return 0;
        }
        int a = 0;
        int b = 1;
        int c;
        int result = 1;
        while (b < len)
        {
            for (int i = a; i < b; i++)
            {
                if (s[i] == s[b])
                {
                    a = i + 1;
                }
            }
            c = b - a + 1;
            if (c > result)
            {
                result = c;
            }
            b++;
        }
        return result;
    }
};

int main()
{
    Solution a;
    a.lengthOfLongestSubstring("pwwkew");

    return 0;

}
