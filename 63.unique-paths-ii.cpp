/*
 * @lc app=leetcode.cn id=63 lang=cpp
 * @lcpr version=30204
 *
 * [63] 不同路径 II
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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // 利用动态规划
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long>> dp(n, vector<long>(m, 0));

        dp[0][0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
    // 回溯法，资源消耗太多
    // int res = 0;
    // int lineNum = 1;
    // int lineSize = 1;
    // int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    // 
    //     lineNum = obstacleGrid.size();
    //     lineSize = obstacleGrid[0].size();
    //     if (obstacleGrid[lineNum - 1][lineSize - 1] == 1 || obstacleGrid[0][0] == 1)
    //     {
    //         return 0;
    //     }
    //     res = 0;
    //     obstacleGrid[0][0] = 1;
    //     dfs(obstacleGrid, 0, 0);
    //     return res;
    // }
    // void dfs(vector<vector<int>> obstacleGrid, int x, int y)
    // {
    //     if (x == lineNum - 1 && y == lineSize - 1)
    //     {
    //         res++;
    //         return;
    //     }
    //     if (x + 1 >= 0 && x + 1 < lineNum && obstacleGrid[x + 1][y] == 0)
    //     {
    //         obstacleGrid[x + 1][y] = 1;
    //         dfs(obstacleGrid, x + 1, y);
    //         obstacleGrid[x + 1][y] = 0;
    //     }
    //     if (y + 1 >= 0 && y + 1 < lineSize && obstacleGrid[x][y + 1] == 0)
    //     {
    //         obstacleGrid[x][y + 1] = 1;
    //         dfs(obstacleGrid, x, y + 1);
    //         obstacleGrid[x][y + 1] = 0;
    //     }
    // }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,0],[0,1,0],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1],[0,0]]\n
// @lcpr case=end

 */
