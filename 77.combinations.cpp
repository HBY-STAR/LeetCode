/*
 * @lc app=leetcode.cn id=77 lang=cpp
 * @lcpr version=30204
 *
 * [77] 组合
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
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<bool> mark;
        for (int i = 0; i <= n; i++)
        {
            mark.push_back(false);
        }

        backtrace(n, 0, 1, k, mark, res);

        return res;
    }

    void backtrace(int n, int currentK, int start, int k, vector<bool> &mark, vector<vector<int>> &res)
    {
        if (currentK == k)
        {
            vector<int> temp;
            for (int i = 1; i <= n; i++)
            {
                if (mark[i])
                {
                    temp.push_back(i);
                }
            }
            res.push_back(temp);
        }

        for (int i = start; i <= n; i++)
        {
            if (!mark[i])
            {
                mark[i] = true;
                backtrace(n, currentK + 1, i + 1, k, mark, res);
                mark[i] = false;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n2\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

 */
