/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30204
 *
 * [238] 除自身以外数组的乘积
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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);
        vector<int> res(nums.size(), 0);

        int temp = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            temp *= nums[i];
            prefix[i] = temp;
        }

        temp = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            temp *= nums[i];
            suffix[i] = temp;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int tempRes = 1;
            if (i - 1 >= 0)
            {
                tempRes *= prefix[i - 1];
            }
            if (i + 1 < nums.size())
            {
                tempRes *= suffix[i + 1];
            }
            res[i] = tempRes;
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */
