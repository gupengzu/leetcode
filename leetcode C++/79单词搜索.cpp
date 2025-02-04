#include<iostream>
#include<vector>
using namespace std;

class Solution
{
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int len = word.size();
        int len_now = 0;
        for (int i = 0; i < board.size();i++)
        {
            for (int k = 0; k < board[0].size();k++)
            {
                if(exist_around(board,word,i,k,0))
                    return true;
            }
        }
        return false;
    }
    bool exist_around(vector<vector<char>>&board,string word,int x,int y,int index)
    {
        if(board[x][y]!=word[index])
            return false;
        if(index==word.size()-1)
            return true;
        char temp = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].size()||board[nx][ny]=='.')
            {
                continue;
            }
            if(exist_around(board, word, nx, ny, index + 1))
            {
                return true;
            }
        }
        board[x][y] = temp;
        return false;
    }
};