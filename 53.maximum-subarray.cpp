/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30204
 *
 * [53] 最大子数组和
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
    int maxSubArray(vector<int> &nums)
    {
        // 利用动态规划
        // dp[i] = max(nums[i], dp[i-1] + nums[i])

        int len = nums.size();
        vector<int> dp;

        for (int i = 0; i < len; i++)
        {
            dp.push_back(nums[i]);
        }

        for (int i = 1; i < len; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }

        int res = INT32_MIN;

        for (int i = 0; i < len; i++)
        {
            res = max(dp[i], res);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
