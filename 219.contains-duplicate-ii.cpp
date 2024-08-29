/*
 * @lc app=leetcode.cn id=219 lang=cpp
 * @lcpr version=30204
 *
 * [219] 存在重复元素 II
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
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> s;
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            if (i > k)
            {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i]))
            {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,1,2,3]\n2\n
// @lcpr case=end

 */
