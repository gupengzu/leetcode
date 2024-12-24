#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
        {
            return res;
        }
        map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string current;
        backtrack(res, phoneMap, digits, 0, current);
        return res;
    }

private:
    void backtrack(vector<string> &res, map<char, string> &phoneMap, string &digits, int index, string &current)
    {
        if (index == digits.size())
        {
            res.push_back(current);
            return;
        }
        char digit = digits[index];
        string letters = phoneMap[digit];
        for (char letter : letters)
        {
            current.push_back(letter);
            backtrack(res, phoneMap, digits, index + 1, current);
            current.pop_back();
        }
    }
};

int main()
{
    Solution s;
    string digits = "23";
    vector<string> combinations = s.letterCombinations(digits);
    for (const string &combination : combinations)
    {
        cout << combination << endl;
    }
    return 0;
}