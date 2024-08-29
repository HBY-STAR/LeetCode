/*
 * @lc app=leetcode.cn id=202 lang=cpp
 * @lcpr version=30204
 *
 * [202] 快乐数
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
    bool isHappy(int n)
    {
        int slow = n, fast = n;
        do
        {
            slow = bitSum(slow);
            fast = bitSum(fast);
            fast = bitSum(fast);
        } while (slow != fast);
        return slow == 1;
    }

    int bitSum(int n)
    {
        int ret = 0;
        while (n != 0)
        {
            int bit = n % 10;
            ret += bit * bit;
            n = n / 10;
        }
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 19\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
