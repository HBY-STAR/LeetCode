/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, INT64_MIN, INT64_MAX);
    }

    bool dfs(TreeNode *root, long m_min, long m_max)
    {
        if (!(root->val < m_max && root->val > m_min))
        {
            return false;
        }
        if (root->left && root->right)
        {
            return dfs(root->left, m_min, std::min(long(root->val), m_max)) && dfs(root->right, std::max(long(root->val), m_min), m_max);
        }
        else if (root->left)
        {
            return dfs(root->left, m_min, std::min(long(root->val), m_max));
        }
        else if (root->right)
        {
            return dfs(root->right, std::max(long(root->val), m_min), m_max);
        }
        else
        {
            return true;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */
