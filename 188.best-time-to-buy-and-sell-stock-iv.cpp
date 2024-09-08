/*
 * @lc app=leetcode.cn id=188 lang=cpp
 * @lcpr version=30204
 *
 * [188] 买卖股票的最佳时机 IV
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
    int maxProfit(int k, vector<int> &prices)
    {
        vector<array<int, 2>> f(k + 2, {INT_MIN / 2, INT_MIN / 2});
        for (int i = 1; i < k + 2; i++)
        {
            f[i][0] = 0;
        }

        for (auto p : prices)
        {
            for (int j = k + 1; j > 0; j--)
            {
                f[j][0] = max(f[j][0], f[j][1] + p);
                f[j][1] = max(f[j][1], f[j - 1][0] - p);
            }
        }

        return f[k + 1][0];
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[2,4,1]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[3,2,6,5,0,3]\n
// @lcpr case=end

 */
