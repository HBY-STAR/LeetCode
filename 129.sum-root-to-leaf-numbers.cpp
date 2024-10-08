/*
 * @lc app=leetcode.cn id=129 lang=cpp
 * @lcpr version=30204
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <string>
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
    int sumNumbers(TreeNode *root)
    {
        string curNums;
        int sumNum = 0;

        dfs(root, curNums, sumNum);

        return sumNum;
    }

    void dfs(TreeNode *root, string &curNum, int &sumNum)
    {
        if (!root)
        {
            return;
        }
        else
        {
            curNum.push_back('0' + root->val);
            if (root->left || root->right)
            {
                dfs(root->left, curNum, sumNum);
                dfs(root->right, curNum, sumNum);
            }
            else
            {
                sumNum += std::stoi(curNum);
            }
            curNum.pop_back();
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,0,5,1]\n
// @lcpr case=end

 */
