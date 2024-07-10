/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;

        vector<int> current;
        vector<bool> leftIndex;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            leftIndex.push_back(true);
        }

        backtrack(res, current, leftIndex, nums);

        return res;
    }

    void backtrack(vector<vector<int>> &res, vector<int> current, vector<bool> leftIndex, vector<int> &nums)
    {
        if (current.size() == nums.size())
        {
            res.push_back(current);
            return;
        }

        for (int i = 0; i < leftIndex.size(); i++)
        {
            if (leftIndex[i])
            {
                current.push_back(nums[i]);
                leftIndex[i] = false;
                backtrack(res, current, leftIndex, nums);
                leftIndex[i] = true;
                current.pop_back();
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
