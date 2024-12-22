//#include<iostream>
//#include<string.h>
//using namespace std;
//
//class Solution
//{
//public:
//    string convert(string s, int numRows)
//    {
//        if (numRows == 1)
//        {
//            return s;
//        }
//        int sizeofS = s.size();
//        int onelist = 2 * numRows - 2;
//        int listnum = s.size() / onelist + 1;
//        int left = 0;
//        string result = s;
//        int add = (listnum * onelist - s.size());
//        for (int i = 0; i < add; i++)
//        {
//            s += '0';
//        }
//        int right = onelist - 1;
//        int index = 0;
//        while (left < s.size())
//        {
//            if (s[left] != '0')
//            {
//                result[index] = s[left];;
//                index++;
//            }
//            left += onelist;
//        }
//        left = 1;
//        while (left <= right)
//        {
//            while (right < s.size())
//            {
//                if (left == right)
//                {
//                    if (s[left] != '0')
//                    {
//                        result[index] = s[left];
//                        index++;
//                    }
//                    left += onelist;
//                    right += onelist;
//                }
//                else
//                {
//                    if (s[left] != '0')
//                    {
//                        result[index] = s[left];
//                        index++;
//                    }
//                    if (s[right] != '0')
//                    {
//                        result[index] = s[right];
//                        index++;
//                    }
//                    left += onelist;
//                    right += onelist;
//                }
//            }
//            left = left - listnum * onelist;
//            right = right - listnum * onelist;
//            left++;
//            right--;
//        }
//        return result;
//    }
//};
//
//int main()
//{
//    return 0;
//}