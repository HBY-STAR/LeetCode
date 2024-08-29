/*
 * @lc app=leetcode.cn id=100 lang=cpp
 * @lcpr version=30204
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p && q && p->val == q->val)
        {
            if (p->left && q->left && p->right && q->right)
            {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            else
            {
                if (p->left && !q->left || !p->left && q->left || p->right && !q->right || !p->right && q->right)
                {
                    return false;
                }
                else
                {
                    if (p->left && q->left)
                    {
                        return isSameTree(p->left, q->left);
                    }
                    else if (p->right && q->right)
                    {
                        return isSameTree(p->right, q->right);
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            if (!p && !q)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[1,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1]\n[1,1,2]\n
// @lcpr case=end

 */
