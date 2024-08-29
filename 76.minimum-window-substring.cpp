// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30204
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t)
    {
        unordered_map<char, int> word;
        unordered_map<char, int> temp;
        for (auto &ch : t)
        {
            word[ch]++;
        }
        for (auto &pair : word)
        {
            temp[pair.first] = 0;
        }

        int a = 0, b = 0;
        int minWindow = INT32_MAX;
        int minA = 0, minB = 0;
        while (a < s.size())
        {
            if (checkOk(word, temp))
            {
                if (b - a < minWindow)
                {
                    minWindow = b - a;
                    minA = a;
                    minB = b;
                }

                temp[s[a]]--;
                a++;
            }
            else if (b < s.size())
            {
                temp[s[b]]++;
                b++;
            }
            else
            {
                a++;
            }
        }

        return s.substr(minA, minB - minA);
    }

    bool checkOk(unordered_map<char, int> &word, unordered_map<char, int> &temp)
    {
        for (auto &pair : word)
        {
            if (temp[pair.first] < word[pair.first])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */
