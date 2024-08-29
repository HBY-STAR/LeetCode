/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30204
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int> &prices)
    {
        // 利用动态规划
        // dp[i] 为第i天卖出得到的最大利润

        int len = prices.size();
        vector<int> dp(len, 0);

        int min = prices[0];
        dp[0] = 0;

        for (int i = 1; i < len; i++)
        {
            dp[i] = max(prices[i] - min, 0);

            if (prices[i] < min)
            {
                min = prices[i];
            }
        }

        int res = 0;

        for (int i = 0; i < len; i++)
        {
            if (dp[i] > res)
            {
                res = dp[i];
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
