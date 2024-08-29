/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=30204
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> nodes;
        DFS(root, nodes);
        int min = INT32_MAX;

        for (int i = 0; i < nodes.size() - 1; i++)
        {
            if (nodes[i + 1] - nodes[i] < min)
            {
                min = nodes[i + 1] - nodes[i];
            }
        }

        return min;
    }

    void DFS(TreeNode *root, vector<int> &nodes)
    {
        if (root)
        {
            DFS(root->left, nodes);
            nodes.push_back(root->val);
            DFS(root->right, nodes);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */
