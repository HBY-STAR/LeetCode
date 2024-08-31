/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30204
 *
 * [80] 删除有序数组中的重复项 II
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
    int removeDuplicates(vector<int> &nums)
    {
        int curNum = INT32_MAX;
        int curCount = 0;
        int deleteCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == curNum)
            {
                if (curCount < 2)
                {
                    curCount++;
                }
                else
                {
                    nums[i] = INT32_MAX;
                    deleteCount++;
                }
            }
            else
            {
                curNum = nums[i];
                curCount = 1;
            }
        }
        for (int i = 0, j = 0; j < nums.size(); j++)
        {
            if (nums[j] != INT32_MAX)
            {
                nums[i] = nums[j];
                i++;
            }
        }

        return nums.size() - deleteCount;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
