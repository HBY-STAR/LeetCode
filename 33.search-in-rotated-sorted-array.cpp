/*
 * @lc app=leetcode.cn id=33 lang=cpp
 * @lcpr version=30204
 *
 * [33] 搜索旋转排序数组
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
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();

        if (len < 5)
        {
            for (int i = 0; i < len; i++)
            {
                if (nums[i] == target)
                {
                    return i;
                }
            }
            return -1;
        }

        int left = 0;
        int right = len - 1;

        while (left <= right)
        {
            int middle = (right - left) / 2 + left;

            // 异常值在左边
            if (nums[middle] < nums[left])
            {
                // 查找值在左边
                if (target < nums[middle])
                {
                    right = middle - 1;
                }
                // 查找值可能在左边或者右边
                else if (target > nums[middle])
                {
                    // 查找值在右边
                    if (target < nums[left])
                    {
                        left = middle + 1;
                    }
                    // 查找值在左边
                    else if (target > nums[left])
                    {
                        right = middle - 1;
                    }
                    else
                    {
                        return left;
                    }
                }
                else
                {
                    return middle;
                }
            }
            // 异常值在右边
            else if (nums[middle] > nums[right])
            {
                // 查找值在左边或右边
                if (target < nums[middle])
                {
                    // 查找值在左边
                    if (target > nums[right])
                    {
                        right = middle - 1;
                    }
                    // 查找值在右边
                    else if (target < nums[right])
                    {
                        left = middle + 1;
                    }
                    else
                    {
                        return right;
                    }
                }
                // 查找值在右边
                else if (target > nums[middle])
                {
                    left = middle + 1;
                }
                else
                {
                    return middle;
                }
            }
            // 无异常值
            else
            {
                // 查找值在左边
                if (target < nums[middle])
                {
                    right = middle - 1;
                }
                // 查找值在右边
                else if (target > nums[middle])
                {
                    left = middle + 1;
                }
                else
                {
                    return middle;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,6,7,0,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [4,5,6,7,0,1,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */
