/*
 * @lc app=leetcode.cn id=28 lang=cpp
 * @lcpr version=30118
 *
 * [28] 找出字符串中第一个匹配项的下标
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
    int strStr(string haystack, string needle)
    {
        int Len1 = haystack.size();
        int Len2 = needle.size();

        for (int i = 0; i < Len1 - Len2 + 1; i++)
        {
            if (needle.compare(haystack.substr(i, Len2)) == 0)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "sadbutsad"\n"sad"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n"leeto"\n
// @lcpr case=end

 */
