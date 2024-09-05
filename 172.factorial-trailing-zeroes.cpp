/*
 * @lc app=leetcode.cn id=172 lang=cpp
 * @lcpr version=30204
 *
 * [172] 阶乘后的零
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
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n / 5;
            n /= 5;
        }

        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

 */
