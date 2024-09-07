/*
 * @lc app=leetcode.cn id=230 lang=cpp
 * @lcpr version=30204
 *
 * [230] 二叉搜索树中第 K 小的元素
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
    int res = -1;
    int kthSmallest(TreeNode *root, int k)
    {
        res = -1;
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode *root, int &k)
    {
        if (root)
        {
            if (root->left && k > 0)
            {
                dfs(root->left, k);
            }

            if (k == 1)
            {
                res = root->val;
            }
            k--;

            if (root->right && k > 0)
            {
                dfs(root->right, k);
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,1,4,null,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n3\n
// @lcpr case=end

 */
