/*
 * @lc app=leetcode.cn id=228 lang=cpp
 * @lcpr version=30204
 *
 * [228] 汇总区间
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
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.size() == 0)
        {
            return res;
        }
        else if (nums.size() == 1)
        {
            res.push_back(getInterval(nums[0], nums[0]));
            return res;
        }

        int left = 0;
        int right = 0;
        for (right = 0; right < nums.size(); right++)
        {
            if (long(right - left) == long(nums[right]) - long(nums[left]))
            {
                if (right + 1 == nums.size())
                {
                    res.push_back(getInterval(nums[left], nums[right]));
                }
            }
            else
            {
                res.push_back(getInterval(nums[left], nums[right - 1]));
                left = right;
            }
        }

        if (right == nums.size() && left == right - 1)
        {
            res.push_back(getInterval(nums[left], nums[left]));
        }

        return res;
    }

    string getInterval(int left, int right)
    {
        string ret;

        if (left == right)
        {
            ret += to_string(left);
            return ret;
        }

        ret += to_string(left);
        ret += "->";
        ret += to_string(right);
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,2,4,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [0,2,3,4,6,8,9]\n
// @lcpr case=end

 */
