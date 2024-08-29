/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30204
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s)
    {
        string temp = "";

        for (auto ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                temp += ch + ('a' - 'A');
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                temp += ch;
            }
            else if (ch >= '0' && ch <= '9')
            {
                temp += ch;
            }
            else
            {
                continue;
            }
        }

        string reverse = "";

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            reverse += temp[i];
        }

        return temp == reverse;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */
