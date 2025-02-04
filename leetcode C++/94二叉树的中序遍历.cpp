#include<iostream>
#include<vector>
using namespace std;


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution 
{
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        if(root==nullptr)
        {
            return result;
        }
        vector<int>left_vector= inorderTraversal(root->left);
        result.insert(result.begin(), left_vector.begin(), left_vector.end());
        result.push_back(root->val);
        vector<int>right_vector= inorderTraversal(root->right);
        result.insert(result.end(), right_vector.begin(), right_vector.end());
        return result;
    }
};