/*
 * @lc app=leetcode.cn id=133 lang=cpp
 * @lcpr version=30204
 *
 * [133] 克隆图
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<int, Node *> mark;
        return dfs(node, mark);
    }

    Node *dfs(Node *node, unordered_map<int, Node *> &mark)
    {
        if (!node)
        {
            return nullptr;
        }

        if (!mark.count(node->val))
        {
            Node *copyNode = new Node(node->val);
            mark[node->val] = copyNode;
            for (auto neighbor : node->neighbors)
            {
                Node *tempNode = dfs(neighbor, mark);
                if (tempNode)
                {
                    copyNode->neighbors.push_back(tempNode);
                }
            }

            return copyNode;
        }
        else
        {
            return mark[node->val];
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,4],[1,3],[2,4],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
