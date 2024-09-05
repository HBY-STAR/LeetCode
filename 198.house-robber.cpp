/*
 * @lc app=leetcode.cn id=198 lang=cpp
 * @lcpr version=30204
 *
 * [198] 打家劫舍
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
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        // 利用动态规划，dp1[i]定义为前i个房屋的最大金额且使用第i个房屋，dp2[i]不使用第i个。
        int len = nums.size();
        vector<int> dp1(len + 1, 0);
        vector<int> dp2(len + 1, 0);
        dp1[1] = nums[0];
        dp2[1] = 0;

        for (int i = 2; i <= len; i++)
        {
            dp1[i] = max(dp1[i - 2] + nums[i - 1], dp2[i - 1] + nums[i - 1]);
            dp2[i] = max(dp1[i - 1], dp2[i - 1]);
        }

        return max(dp1[len], dp2[len]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

 */
