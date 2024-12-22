//#include<iostream>
//#include<string>
//#include<climits>
//using namespce std;
//
//
//class Solution
//{
//public:
//    int reverse(int x)
//    {
//        int temp = 0;
//        int result = 0;
//        while (x != 0)
//        {
//            temp = x % 10;
//            x = x / 10;
//            if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && temp > 7))
//            {
//                return 0;
//            }
//            if (result < INT32_MIN / 10 || (result == INT32_MIN / 10 && temp < (-8)))
//            {
//                return 0;
//            }
//            result = result * 10 + temp;
//        }
//        return result;
//    }
//};
//
//int main()
//{
//    return 0;
//}