/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * @lcpr version=30204
 *
 * [215] 数组中的第K个最大元素
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
    // int findKthLargest(vector<int> &nums, int k)
    // {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() - k];
    // }

    int findKthLargest(vector<int> &nums, int k)
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int range = maxVal - minVal + 1;

        vector<int> count(range, 0);

        for (int num : nums)
        {
            count[num - minVal]++;
        }

        for (int i = range - 1; i >= 0; --i)
        {
            k -= count[i];
            if (k <= 0)
            {
                return i + minVal;
            }
        }

        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
