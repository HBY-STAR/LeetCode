/*
 * @lc app=leetcode.cn id=64 lang=cpp
 * @lcpr version=30204
 *
 * [64] 最小路径和
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
    int minPathSum(vector<vector<int>> &grid)
    {
        const int MAX = 9999;
        // 利用动态规划
        int n = grid.size(), m = grid[0].size();
        vector<vector<long>> dp(n, vector<long>(m, MAX));

        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int up = MAX;
                int left = MAX;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = min(long(up + grid[i][j]), dp[i][j]);

                dp[i][j] = min(long(left + grid[i][j]), dp[i][j]);
            }
        }

        return dp[n - 1][m - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,1],[1,5,1],[4,2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6]]\n
// @lcpr case=end

 */
