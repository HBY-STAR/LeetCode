/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return true;
        }
        else if (root->left && root->right)
        {
            if (root->left->val == root->right->val)
            {
                return isSymmetricNode(root->left, root->right);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    bool isSymmetricNode(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }
        else if (a && b)
        {
            if (a->val == b->val)
            {
                return isSymmetricNode(a->left, b->right) && isSymmetricNode(a->right, b->left);
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */
