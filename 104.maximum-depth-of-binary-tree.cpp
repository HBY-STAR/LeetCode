/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30204
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        if (root)
        {
            return DFS(root, 1);
        }
        else
        {
            return 0;
        }
    }

    int DFS(TreeNode *root, int curDepth)
    {
        if (!root)
        {
            return curDepth;
        }
        else
        {
            if (root->left && root->right)
            {
                return max(DFS(root->left, curDepth + 1), DFS(root->right, curDepth + 1));
            }
            else if (root->left)
            {
                return DFS(root->left, curDepth + 1);
            }
            else if (root->right)
            {
                return DFS(root->right, curDepth + 1);
            }
            else
            {
                return curDepth;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */
