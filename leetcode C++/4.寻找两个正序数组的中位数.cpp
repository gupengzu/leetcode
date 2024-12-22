#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int a = 0;
        int b = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> c(len1 + len2);
        int index = 0;
        while (a < len1 && b < len2)
        {
            if (nums1[a] < nums2[b])
            {
                c[index] = nums1[a];
                a++;
                index++;
            }
            else
            {
                c[index] = nums2[b];
                b++;
                index++;
            }
        }
        while (a < len1)
        {
            c[index] = nums1[a];
            a++;
            index++;
        }
        while (b < len2)
        {
            c[index] = nums2[b];
            b++;
            index++;
        }
        int left = 0;
        int right = c.size() - 1;
        double result = c[0];
        if ((c.size() % 2) == 1)
        {
            result = c[(right + left) / 2];
        }
        else
        {
            double a = c[(right + left) / 2];
            double b = c[(right + left + 1) / 2];
            result = (a + b) / 2;
        }
        return result;
    }
};

int main()
{
    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = { 2 };
    Solution s;
    s.findMedianSortedArrays(nums1, nums2);
    return 0;
}