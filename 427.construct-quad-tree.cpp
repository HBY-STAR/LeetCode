/*
 * @lc app=leetcode.cn id=427 lang=cpp
 * @lcpr version=30204
 *
 * [427] 建立四叉树
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
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        Node *root = dfs(grid, 0, 0, n);
        return root;
    }

    Node *dfs(vector<vector<int>> &grid, int start_i, int start_j, int n)
    {
        bool allOne = true;
        bool allZero = true;
        for (int i = start_i; i < start_i + n; i++)
        {
            for (int j = start_j; j < start_j + n; j++)
            {
                if (grid[i][j] == 1)
                {
                    allZero = false;
                }
                else
                {
                    allOne = false;
                }

                if (!allOne && !allZero)
                {
                    break;
                }
            }
        }

        if (allOne || allZero)
        {
            Node *leaf = new Node(allOne, true);
            return leaf;
        }
        else
        {
            Node *tl = dfs(grid, start_i, start_j, n / 2);
            Node *tr = dfs(grid, start_i, start_j + n / 2, n / 2);
            Node *bl = dfs(grid, start_i + n / 2, start_j, n / 2);
            Node *br = dfs(grid, start_i + n / 2, start_j + n / 2, n / 2);

            Node *root = new Node(true, false, tl, tr, bl, br);
            return root;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]\n
// @lcpr case=end

 */
