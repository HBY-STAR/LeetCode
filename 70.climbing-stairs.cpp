/*
 * @lc app=leetcode.cn id=70 lang=cpp
 * @lcpr version=30118
 *
 * [70] 爬楼梯
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
    int climbStairs(int n)
    {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */
