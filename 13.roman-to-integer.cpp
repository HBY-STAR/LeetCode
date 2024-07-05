/*
 * @lc app=leetcode.cn id=13 lang=cpp
 * @lcpr version=30117
 *
 * [13] 罗马数字转整数
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
    int romanToInt(string s)
    {
        int romanNumerals[256] = {0};
        romanNumerals['I'] = 1;
        romanNumerals['V'] = 5;
        romanNumerals['X'] = 10;
        romanNumerals['L'] = 50;
        romanNumerals['C'] = 100;
        romanNumerals['D'] = 500;
        romanNumerals['M'] = 1000;

        int Len = s.size();
        int result = 0;
        int temp = 0;

        int beforeNum = 9999;

        for (int i = 0; i < Len; i++)
        {
            temp = romanNumerals[s[i]];
            if (beforeNum < temp)
            {
                result -= 2 * beforeNum;
            }

            result += temp;
            beforeNum = temp;
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "III"\n
// @lcpr case=end

// @lcpr case=start
// "IV"\n
// @lcpr case=end

// @lcpr case=start
// "IX"\n
// @lcpr case=end

// @lcpr case=start
// "LVIII"\n
// @lcpr case=end

// @lcpr case=start
// "MCMXCIV"\n
// @lcpr case=end

 */
