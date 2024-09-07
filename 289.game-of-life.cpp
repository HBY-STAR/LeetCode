/*
 * @lc app=leetcode.cn id=289 lang=cpp
 * @lcpr version=30204
 *
 * [289] 生命游戏
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
    vector<vector<int>> near = {{0, 1},
                                {0, -1},
                                {1, 0},
                                {1, 1},
                                {1, -1},
                                {-1, 0},
                                {-1, 1},
                                {-1, -1}};
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> nextBoard(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                int count = liveCount(board, i, j);
                if (board[i][j] == 1)
                {
                    if (count < 2 || count > 3)
                    {
                        nextBoard[i][j] = 0;
                    }
                    else
                    {
                        nextBoard[i][j] = 1;
                    }
                }
                else
                {
                    if (count == 3)
                    {
                        nextBoard[i][j] = 1;
                    }
                    else
                    {
                        nextBoard[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] = nextBoard[i][j];
            }
        }
    }

    int liveCount(vector<vector<int>> &board, int i, int j)
    {
        int res = 0;
        for (int m = 0; m < near.size(); m++)
        {
            if (i + near[m][0] >= 0 &&
                i + near[m][0] < board.size() &&
                j + near[m][1] >= 0 &&
                j + near[m][1] < board[0].size() &&
                board[i + near[m][0]][j + near[m][1]] == 1)
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,0]]\n
// @lcpr case=end

 */
