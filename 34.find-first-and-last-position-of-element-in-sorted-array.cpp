/*
 * @lc app=leetcode.cn id=34 lang=cpp
 * @lcpr version=30204
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
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
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int len = nums.size();
        vector<int> ret;

        ret.push_back(-1);
        ret.push_back(-1);

        if (len < 5)
        {
            for (int i = 0; i < len; i++)
            {
                if (target == nums[i])
                {
                    ret[1] = i;
                }
            }

            for (int i = ret[1]; i >= 0; i--)
            {
                if (target == nums[i])
                {
                    ret[0] = i;
                }
                else
                {
                    break;
                }
            }

            return ret;
        }

        int left = 0;
        int right = len - 1;

        int find = -1;

        while (left <= right)
        {
            int middle = (right - left) / 2 + left;

            if (target == nums[middle])
            {
                find = middle;
                break;
            }
            else if (target > nums[middle])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        if (find == -1)
        {
            return ret;
        }

        for (int i = find; i >= 0; i--)
        {
            if (target == nums[i])
            {
                ret[0] = i;
            }
            else
            {
                break;
            }
        }

        for (int i = find; i < len; i++)
        {
            if (target == nums[i])
            {
                ret[1] = i;
            }
            else
            {
                break;
            }
        }

        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,7,8,8,10]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,7,7,8,8,10]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n0\n
// @lcpr case=end

 */
