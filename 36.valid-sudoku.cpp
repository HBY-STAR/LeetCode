/*
 * @lc app=leetcode.cn id=36 lang=cpp
 * @lcpr version=30204
 *
 * [36] 有效的数独
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
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> count;
        count['.'] = -9999;
        count['1'] = 0;
        count['2'] = 0;
        count['3'] = 0;
        count['4'] = 0;
        count['5'] = 0;
        count['6'] = 0;
        count['7'] = 0;
        count['8'] = 0;
        count['9'] = 0;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                count[board[i][j]]++;
                if (count[board[i][j]] > 1)
                {
                    return false;
                }
            }
            count['.'] = -9999;
            count['1'] = 0;
            count['2'] = 0;
            count['3'] = 0;
            count['4'] = 0;
            count['5'] = 0;
            count['6'] = 0;
            count['7'] = 0;
            count['8'] = 0;
            count['9'] = 0;
        }

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                count[board[j][i]]++;
                if (count[board[j][i]] > 1)
                {
                    return false;
                }
            }
            count['.'] = -9999;
            count['1'] = 0;
            count['2'] = 0;
            count['3'] = 0;
            count['4'] = 0;
            count['5'] = 0;
            count['6'] = 0;
            count['7'] = 0;
            count['8'] = 0;
            count['9'] = 0;
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        count[board[k][l]]++;
                        if (count[board[k][l]] > 1)
                        {
                            return false;
                        }
                    }
                }
                count['.'] = -9999;
                count['1'] = 0;
                count['2'] = 0;
                count['3'] = 0;
                count['4'] = 0;
                count['5'] = 0;
                count['6'] = 0;
                count['7'] = 0;
                count['8'] = 0;
                count['9'] = 0;
            }
        }

        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

// @lcpr case=start
// [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]\n
// @lcpr case=end

 */
