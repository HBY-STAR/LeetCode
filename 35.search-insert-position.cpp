/*
 * @lc app=leetcode.cn id=35 lang=cpp
 * @lcpr version=30118
 *
 * [35] 搜索插入位置
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
    int searchInsert(vector<int> &nums, int target)
    {
        int Len = nums.size();

        int start = 0;
        int end = Len - 1;
        int middle = 0;

        while (true)
        {
            if (start == end)
            {
                if (target > nums[start])
                {
                    return start + 1;
                }
                else
                {
                    return start;
                }
            }
            if (start == end - 1)
            {
                if (target <= nums[start])
                {
                    return start;
                }
                if (target > nums[end])
                {
                    return end + 1;
                }
                else
                {
                    return end;
                }
            }
            middle = (end - start) / 2;
            if (nums[middle + start] == target)
            {
                return middle + start;
            }
            else if (nums[middle + start] < target)
            {
                start = middle + start;
            }
            else
            {
                end = middle + start;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3,5,6]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,6]\n7\n
// @lcpr case=end

 */
