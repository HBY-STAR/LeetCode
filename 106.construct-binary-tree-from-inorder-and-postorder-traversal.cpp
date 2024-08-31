/*
 * @lc app=leetcode.cn id=106 lang=cpp
 * @lcpr version=30204
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int, int> post2in;
    unordered_map<int, int> in2post;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < postorder.size(); i++)
        {
            for (int j = 0; j < inorder.size(); j++)
            {
                if (postorder[i] == inorder[j])
                {
                    post2in[i] = j;
                    in2post[j] = i;
                }
            }
        }

        TreeNode *res = dfs(inorder, postorder, post2in[inorder.size() - 1], 0, inorder.size() - 1);
        return res;
    }

    // 参数均基于 inorder
    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int root, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        TreeNode *temp = new TreeNode(inorder[root]);
        if (in2post[root] - 1 - (right - root) >= 0)
        {
            temp->left = dfs(inorder, postorder, post2in[in2post[root] - 1 - (right - root)], left, root - 1);
        }
        else
        {
            temp->left = nullptr;
        }
        if (in2post[root] - 1 >= 0)
        {
            temp->right = dfs(inorder, postorder, post2in[in2post[root] - 1], root + 1, right);
        }
        else
        {
            temp->right = nullptr;
        }
        return temp;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [9,3,15,20,7]\n[9,15,7,20,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
