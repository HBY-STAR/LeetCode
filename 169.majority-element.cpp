/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30204
 *
 * [169] 多数元素
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
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (auto num : nums)
        {
            count[num]++;
        }

        for (auto pair : count)
        {
            if (pair.second > nums.size() / 2)
            {
                return pair.first;
            }
        }

        return 0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */
