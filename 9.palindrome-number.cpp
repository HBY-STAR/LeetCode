/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=30117
 *
 * [9] 回文数
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
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        else if (x >= 0 && x <= 9)
        {
            return true;
        }
        else
        {
            string temp;

            while (x > 9)
            {
                temp.push_back(char(x % 10));
                x = x / 10;
            }

            temp.push_back(char(x));

            int len = temp.size();
            int mid = temp.size() / 2;

            for (int i = 0; i < mid; i++)
            {
                if (temp[i] != temp[len - i - 1])
                    return false;
            }

            return true;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */
