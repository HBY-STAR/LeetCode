/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30204
 *
 * [128] 最长连续序列
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
    int longestConsecutive(vector<int> &nums)
    {
        int res = 0;
        unordered_set<int> nums_set;

        for (auto num : nums)
        {
            nums_set.insert(num);
        }

        for (const int &num : nums_set)
        {
            if (!nums_set.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while (nums_set.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                res = max(res, currentStreak);
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

 */
