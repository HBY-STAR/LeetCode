/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30118
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string> &strs)
    {
        int Len = strs.size();

        string prefix = strs[0];

        for (int i = 1; i < Len; i++)
        {
            prefix = longestPrefix2(prefix, strs[i]);
        }

        return prefix;
    }

    string longestPrefix2(string &str1, string &str2)
    {
        int Len1 = str1.size();
        int Len2 = str2.size();

        string res;

        int i = 0, j = 0;

        while (i < Len1 && j < Len2)
        {
            if (str1[i] != str2[j])
            {
                break;
            }
            else
            {
                int m = i, n = j;
                while (m < Len1 && n < Len2 && str1[m] == str2[n])
                {
                    res.push_back(str1[m]);
                    m++;
                    n++;
                }
                break;
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
