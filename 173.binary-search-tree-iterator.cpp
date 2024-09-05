/*
 * @lc app=leetcode.cn id=173 lang=cpp
 * @lcpr version=30204
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator
{
public:
    vector<int> array_tree;
    int index = -1;
    BSTIterator(TreeNode *root)
    {
        array_tree.clear();
        dfs(root);
        index = -1;
    }

    void dfs(TreeNode *root)
    {
        if (root)
        {
            dfs(root->left);
            array_tree.push_back(root->val);
            dfs(root->right);
        }
    }

    int next()
    {
        index++;
        return array_tree[index];
    }

    bool hasNext()
    {
        return index + 1 < array_tree.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
