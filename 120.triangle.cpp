/*
 * @lc app=leetcode.cn id=120 lang=cpp
 * @lcpr version=30204
 *
 * [120] 三角形最小路径和
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
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
    // int minPath = INT32_MAX;
    // int sum = 0;

    // int minimumTotal(vector<vector<int>> &triangle)
    // {
    //     minPath = INT32_MAX;
    //     sum = 0;
    //     dfs(triangle, 0, 0);
    //     return minPath;
    // }

    // void dfs(vector<vector<int>> &triangle, int curDepth, int curIndex)
    // {
    //     if (curDepth == triangle.size())
    //     {
    //         if (sum < minPath)
    //         {
    //             minPath = sum;
    //         }
    //         return;
    //     }

    //     if (curDepth < triangle.size() && curIndex < triangle[curDepth].size())
    //     {
    //         sum += triangle[curDepth][curIndex];
    //         dfs(triangle, curDepth + 1, curIndex);
    //         dfs(triangle, curDepth + 1, curIndex + 1);
    //         sum -= triangle[curDepth][curIndex];
    //     }
    // }
};
// @lc code=end

/*
// @lcpr case=start
// [[2],[3,4],[6,5,7],[4,1,8,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[-10]]\n
// @lcpr case=end

 */
