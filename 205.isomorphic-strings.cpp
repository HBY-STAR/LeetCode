/*
 * @lc app=leetcode.cn id=205 lang=cpp
 * @lcpr version=30204
 *
 * [205] 同构字符串
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
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0; i < s.size(); i++)
        {
            if (map1[s[i]] == 0)
            {
                map1[s[i]] = t[i];
            }
            else
            {
                if (map1[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (map2[t[i]] == 0)
            {
                map2[t[i]] = s[i];
            }
            else
            {
                if (map2[t[i]] != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "egg"\n"add"\n
// @lcpr case=end

// @lcpr case=start
// "foo"\n"bar"\n
// @lcpr case=end

// @lcpr case=start
// "paper"\n"title"\n
// @lcpr case=end

 */
