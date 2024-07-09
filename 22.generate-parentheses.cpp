/*
 * @lc app=leetcode.cn id=22 lang=cpp
 * @lcpr version=30204
 *
 * [22] 括号生成
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
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    void backtrack(vector<string> &result, string current, int open, int close, int max)
    {
        if (current.length() == max * 2)
        {
            result.push_back(current);
            return;
        }

        if (open < max)
        {
            backtrack(result, current + "(", open + 1, close, max);
        }
        if (close < open)
        {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
