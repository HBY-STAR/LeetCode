/*
 * @lc app=leetcode.cn id=124 lang=cpp
 * @lcpr version=30204
 *
 * [124] 二叉树中的最大路径和
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
// class Solution
// {
// public:
//     int maxPathSum(TreeNode *root)
//     {
//         unordered_map<TreeNode *, vector<TreeNode *>> graph;
//         unordered_set<TreeNode *> nodes;
//         build_graph(root, graph, nodes);

//         int maxPath = INT_MIN;
//         for (auto node : nodes)
//         {
//             unordered_set<TreeNode *> visited;
//             dfs(node, graph, visited, 0, maxPath);
//         }

//         return maxPath;
//     }

//     void dfs(TreeNode *curNode, unordered_map<TreeNode *, vector<TreeNode *>> &graph, unordered_set<TreeNode *> &visited, int curPath, int &maxPath)
//     {
//         if (!visited.count(curNode))
//         {
//             visited.insert(curNode);
//             curPath += curNode->val;

//             if (curPath > maxPath)
//             {
//                 maxPath = curPath;
//             }

//             for (auto outNode : graph[curNode])
//             {
//                 dfs(outNode, graph, visited, curPath, maxPath);
//             }
//         }
//     }

//     void build_graph(TreeNode *root, unordered_map<TreeNode *, vector<TreeNode *>> &graph, unordered_set<TreeNode *> &nodes)
//     {
//         if (root)
//         {
//             nodes.insert(root);
//             if (root->left)
//             {
//                 graph[root].push_back(root->left);
//                 graph[root->left].push_back(root);
//                 build_graph(root->left, graph, nodes);
//             }
//             if (root->right)
//             {
//                 graph[root].push_back(root->right);
//                 graph[root->right].push_back(root);
//                 build_graph(root->right, graph, nodes);
//             }
//         }
//     }
// };
class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxPath = INT_MIN;
        maxGain(root, maxPath);
        return maxPath;
    }

    int maxGain(TreeNode *node, int &maxPath)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftGain = max(maxGain(node->left, maxPath), 0);
        int rightGain = max(maxGain(node->right, maxPath), 0);

        int currentPath = node->val + leftGain + rightGain;

        maxPath = max(maxPath, currentPath);

        return node->val + max(leftGain, rightGain);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */
