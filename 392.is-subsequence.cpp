/*
 * @lc app=leetcode.cn id=392 lang=cpp
 * @lcpr version=30204
 *
 * [392] 判断子序列
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
    bool isSubsequence(string s, string t)
    {
        int a = 0, b = 0;
        while (a < s.size())
        {
            while (b < t.size() && t[b] != s[a])
            {
                b++;
            }

            if (b == t.size())
            {
                return false;
            }
            else
            {
                a++;
                b++;
            }
        }

        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"ahbgdc"\n
// @lcpr case=end

// @lcpr case=start
// "axc"\n"ahbgdc"\n
// @lcpr case=end

 */
