/*
 * @lc app=leetcode.cn id=114 lang=cpp
 * @lcpr version=30204
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        queue<TreeNode *> q;
        dfs(root, q);

        TreeNode *temp = q.front();
        q.pop();

        while (!q.empty())
        {
            temp->left = nullptr;
            temp->right = q.front();
            temp = q.front();
            q.pop();
        }
    }

    void dfs(TreeNode *root, queue<TreeNode *> &q)
    {
        if (root)
        {
            q.push(root);
            dfs(root->left, q);
            dfs(root->right, q);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,5,3,4,null,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
