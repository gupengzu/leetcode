#include<iostream>
#include<vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if(root==nullptr)
        {
            return result;
        }
        vector<int> left_result = postorderTraversal(root->left);
        result.insert(result.begin(), left_result.begin(), left_result.end());
        vector<int> right_result = postorderTraversal(root->right);
        result.insert(result.end(), right_result.begin(), right_result.end());
        result.push_back(root->val);
        return result;
    }
};