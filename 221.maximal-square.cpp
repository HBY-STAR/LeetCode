/*
 * @lc app=leetcode.cn id=221 lang=cpp
 * @lcpr version=30204
 *
 * [221] 最大正方形
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
// class Solution
// {
// public:
//     int maxSize = 0;
//     int maximalSquare(vector<vector<char>> &matrix)
//     {
//         maxSize = 0;
//         for (int i = 0; i < matrix.size(); i++)
//         {
//             for (int j = 0; j < matrix[0].size(); j++)
//             {
//                 dfs(matrix, 0, i, j);
//             }
//         }

//         return maxSize * maxSize;
//     }

//     void dfs(vector<vector<char>> &matrix, int curSize, int i, int j)
//     {
//         if (i < matrix.size() && j < matrix[0].size() && matrix[i][j] == '1')
//         {
//             int flag = true;
//             while (flag)
//             {
//                 curSize = maxSize + 1;
//                 for (int m = i; m < i + curSize; m++)
//                 {
//                     for (int n = j; n < j + curSize; n++)
//                     {
//                         if (m < matrix.size() && n < matrix[0].size() && matrix[m][n] == '1')
//                         {
//                             continue;
//                         }
//                         else
//                         {
//                             flag = false;
//                             break;
//                         }
//                     }
//                 }

//                 if (curSize > maxSize && flag)
//                 {
//                     maxSize = curSize;
//                 }
//             }
//         }
//     }
// };

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        // 利用动态规划，dp[i][j]定义为以i,j为右下角的最大的正方形。
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSize = 0;

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }

        return maxSize * maxSize;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0","1"],["1","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["0"]]\n
// @lcpr case=end

 */
