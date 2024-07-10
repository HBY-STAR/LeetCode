/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=30204
 *
 * [45] 跳跃游戏 II
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
    int jump(vector<int> &nums)
    {
        // 动态规划，dp[i]定义为到达 i 位置所需的最小步数
        // dp[i + (1~nums[i])] = dp[i] + 1

        int len = nums.size();

        vector<int> dp;
        for (int i = 0; i < len; i++)
        {
            dp.push_back(INT32_MAX);
        }
        dp[0] = 0;

        for (int i = 0; i < len; i++)
        {
            int step = nums[i];

            for (int j = 1; j <= step; j++)
            {
                if (i + j < len)
                {
                    if (dp[i + j] > dp[i] + 1)
                    {
                        dp[i + j] = dp[i] + 1;
                    }
                }
            }
        }

        return dp[len - 1];
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */
