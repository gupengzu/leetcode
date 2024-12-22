//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//
//class Solution
//{
//public:
//    int jump(vector<int>& nums)
//    {
//        int len = nums.size() - 1;
//        if (len == 0)
//        {
//            return 0;
//        }
//        int now = 0;
//        int times = 0;
//        while (now < len)
//        {
//            int nowandnextcanjump = 0;
//            int nowwilljump = 0;
//            for (int i = 0; i < nums[now]; i++)
//            {
//                int thisnowandnextcanjump = i + 1 + nums[now + i + 1];
//                if (thisnowandnextcanjump >= nowandnextcanjump)
//                {
//                    if ((now + i + 1) > len)
//                    {
//                        return times + 1;
//                    }
//                    nowandnextcanjump = thisnowandnextcanjump;
//                    nowwilljump = i + 1;
//                }
//            }
//            now += nowwilljump;
//            times += 1;
//        }
//        return times;
//    }
//};
