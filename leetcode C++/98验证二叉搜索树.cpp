#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    bool isValidBST(TreeNode *root)
    {
        return isvalid(root, LLONG_MIN, LLONG_MAX);
    }
    bool isvalid(TreeNode *root, long left_value, long right_value)
    {
        if (root == nullptr)
        {
            return true;
        }
        bool result = false;
        bool left_result = true;
        bool right_result = true;

        if (root->left != nullptr && root->left->val >= root->val)
        {
            return false;
        }
        if (root->right != nullptr && root->right->val <= root->val)
        {
            return false;
        }

        if (root->left != nullptr)
        {
            bool left_right = right_point_must_small(root->left, root->val);
            bool left_left = left_point_must_large(root->left, left_value);
            left_result = left_left && left_right && isvalid(root->left, left_value, root->val);
        }
        if (root->right != nullptr)
        {
            bool right_left = left_point_must_large(root->right, root->val);
            bool right_right = right_point_must_small(root->right, right_value);
            right_result = right_left && right_right && isvalid(root->right, root->val, right_value);
        }
        result = left_result && right_result;
        return result;
    }
    bool right_point_must_small(TreeNode *root, long right_father_value)
    {
        if (root->right != nullptr && root->right->val >= right_father_value)
        {
            return false;
        }
        return true;
    }
    bool left_point_must_large(TreeNode *root, long left_father_value)
    {
        if (root->left != nullptr && root->left->val <= left_father_value)
        {
            return false;
        }
        return true;
    }
};