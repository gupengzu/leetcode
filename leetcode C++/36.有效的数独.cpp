//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution
//{
//public:
//    bool isValidSudoku(vector<vector<char>>& board)
//    {
//        vector<char> test(9, 0);
//        for (int i = 0; i < 9; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                switch (board[i][j])
//                {
//                case '1':
//                    test[0]++;
//                    break;
//                case '2':
//                    test[1]++;
//                    break;
//                case '3':
//                    test[2]++;
//                    break;
//                case '4':
//                    test[3]++;
//                    break;
//                case '5':
//                    test[4]++;
//                    break;
//                case '6':
//                    test[5]++;
//                    break;
//                case '7':
//                    test[6]++;
//                    break;
//                case '8':
//                    test[7]++;
//                    break;
//                case '9':
//                    test[8]++;
//                    break;
//                default:
//                    break;
//                }
//            }
//            for (int k = 0; k < 9; k++)
//            {
//                if (test[k] > 1)
//                {
//                    return false;
//                }
//            }
//            for (int l = 0; l < 9; l++)
//            {
//                test[l] = 0;
//            }
//            for (int j = 0; j < 9; j++)
//            {
//                switch (board[j][i])
//                {
//                case '1':
//                    test[0]++;
//                    break;
//                case '2':
//                    test[1]++;
//                    break;
//                case '3':
//                    test[2]++;
//                    break;
//                case '4':
//                    test[3]++;
//                    break;
//                case '5':
//                    test[4]++;
//                    break;
//                case '6':
//                    test[5]++;
//                    break;
//                case '7':
//                    test[6]++;
//                    break;
//                case '8':
//                    test[7]++;
//                    break;
//                case '9':
//                    test[8]++;
//                    break;
//                default:
//                    break;
//                }
//            }
//            for (int k = 0; k < 9; k++)
//            {
//                if (test[k] > 1)
//                {
//                    return false;
//                }
//            }
//            for (int l = 0; l < 9; l++)
//            {
//                test[l] = 0;
//            }
//        }
//
//        for (int i = 0; i < 3; i++)
//        {
//            for (int j = 0; j < 3; j++)
//            {
//                for (int k = 0; k < 3; k++)
//                {
//                    for (int l = 0; l < 3; l++)
//                    {
//                        switch (board[3 * i + k][3 * j + l])
//                        {
//                        case '1':
//                            test[0]++;
//                            break;
//                        case '2':
//                            test[1]++;
//                            break;
//                        case '3':
//                            test[2]++;
//                            break;
//                        case '4':
//                            test[3]++;
//                            break;
//                        case '5':
//                            test[4]++;
//                            break;
//                        case '6':
//                            test[5]++;
//                            break;
//                        case '7':
//                            test[6]++;
//                            break;
//                        case '8':
//                            test[7]++;
//                            break;
//                        case '9':
//                            test[8]++;
//                            break;
//                        default:
//                            break;
//                        }
//                    }
//                }
//                for (int k = 0; k < 9; k++)
//                {
//                    if (test[k] > 1)
//                    {
//                        return false;
//                    }
//                }
//                for (int l = 0; l < 9; l++)
//                {
//                    test[l] = 0;
//                }
//            }
//        }
//        return true;
//    }
//};
//
//int main()
//{
//    return 0;
//}