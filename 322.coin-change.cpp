/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30204
 *
 * [322] 零钱兑换
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
    int coinChange(vector<int> &coins, int amount)
    {
        // 利用动态规划，dp[i]定义为amount为i时的最小硬币数；
        const int max = 999999999;
        vector<int> dp(amount + 1, max);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (i - coin >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if (dp[amount] == max)
        {
            return -1;
        }
        else
        {
            return dp[amount];
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
