/*
 * @lc app=leetcode.cn id=137 lang=cpp
 * @lcpr version=30204
 *
 * [137] 只出现一次的数字 II
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
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            for (auto num : nums)
            {
                total += (num >> i) & 1;
            }

            res |= ((total % 3 != 0) << i);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,1,0,1,99]\n
// @lcpr case=end

 */
