/*
 * @lc app=leetcode.cn id=201 lang=cpp
 * @lcpr version=30204
 *
 * [201] 数字范围按位与
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
    int rangeBitwiseAnd(int left, int right)
    {
        while (left < right)
        {
            right = right & (right - 1);
        }
        return right;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n7\n
// @lcpr case=end

// @lcpr case=start
// 0\n0\n
// @lcpr case=end

// @lcpr case=start
// 1\n2147483647\n
// @lcpr case=end

 */
