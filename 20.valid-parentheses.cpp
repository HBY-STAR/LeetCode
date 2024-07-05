/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30118
 *
 * [20] 有效的括号
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
    bool isValid(string s)
    {
        int Len = s.size();

        if (Len % 2 == 1)
        {
            return false;
        }

        stack<char> stack;

        for (int i = 0; i < Len; i++)
        {
            char temp = s[i];

            switch (temp)
            {
            case '(':
            case '[':
            case '{':
            {
                stack.push(temp);
                break;
            }
            case ')':
            {
                if (stack.size() == 0 || stack.top() != '(')
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
                break;
            }

            case ']':
            {
                if (stack.size() == 0 || stack.top() != '[')
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
                break;
            }

            case '}':
            {
                if (stack.size() == 0 || stack.top() != '{')
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
                break;
            }

            default:
                return false;
                break;
            }
        }

        if (stack.size() == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */
