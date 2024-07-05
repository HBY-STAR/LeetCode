/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30117
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s)
    {
        string result;
        string temp;

        for (int i = 0; i < s.size(); i++)
        {
            temp.clear();
            for (int j = i; j < s.size(); j++)
            {
                temp.push_back(s[j]);
                if (temp.size() > result.size())
                {
                    if (checkOk(temp))
                    {
                        result = temp;
                    }
                }
            }
        }

        return result;
    }

    bool checkOk(string &s)
    {
        int len = s.size();
        int mid = s.size() / 2;

        for (int i = 0; i < mid; i++)
        {
            if (s[i] != s[len - i - 1])
                return false;
        }

        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
