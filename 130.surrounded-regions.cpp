/*
 * @lc app=leetcode.cn id=130 lang=cpp
 * @lcpr version=30204
 *
 * [130] 被围绕的区域
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
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        vector<vector<bool>> mark(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++)
        {
            dfs(board, mark, i, 0);
            dfs(board, mark, i, board[0].size() - 1);
        }

        for (int j = 0; j < board[0].size(); j++)
        {
            dfs(board, mark, 0, j);
            dfs(board, mark, board.size() - 1, j);
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (!mark[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &mark, int i, int j)
    {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && !mark[i][j] && board[i][j] == 'O')
        {
            mark[i][j] = true;
            dfs(board, mark, i + 1, j);
            dfs(board, mark, i - 1, j);
            dfs(board, mark, i, j + 1);
            dfs(board, mark, i, j - 1);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]\n
// @lcpr case=end

// @lcpr case=start
// [["X"]]\n
// @lcpr case=end

 */
