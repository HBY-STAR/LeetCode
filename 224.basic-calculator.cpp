/*
 * @lc app=leetcode.cn id=224 lang=cpp
 * @lcpr version=30204
 *
 * [224] 基本计算器
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
    int calculate(string s)
    {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n)
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else if (s[i] == '+')
            {
                sign = ops.top();
                i++;
            }
            else if (s[i] == '-')
            {
                sign = -ops.top();
                i++;
            }
            else if (s[i] == '(')
            {
                ops.push(sign);
                i++;
            }
            else if (s[i] == ')')
            {
                ops.pop();
                i++;
            }
            else
            {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "1 + 1"\n
// @lcpr case=end

// @lcpr case=start
// " 2-1 + 2 "\n
// @lcpr case=end

// @lcpr case=start
// "(1+(4+5+2)-3)+(6+8)"\n
// @lcpr case=end

 */
