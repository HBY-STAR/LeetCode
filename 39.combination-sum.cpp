/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, res, current, 0, target, 0);

        return res;
    }

    void backtrack(vector<int> &candidates, vector<vector<int>> &res, vector<int> current, int currentSum, int target, int start)
    {
        if (currentSum == target)
        {
            res.push_back(current);
            return;
        }

        if (currentSum > target)
        {
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (currentSum + candidates[i] <= target)
            {
                current.push_back(candidates[i]);
                backtrack(candidates, res, current, currentSum + candidates[i], target, i);
                current.pop_back();
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
