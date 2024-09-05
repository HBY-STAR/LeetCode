/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
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
#include <string>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_set<string> operators;
        operators.insert("+");
        operators.insert("-");
        operators.insert("*");
        operators.insert("/");
        stack<int> nums;

        for (auto &token : tokens)
        {
            if (operators.count(token))
            {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();

                int res = 0;

                if (token == "+")
                {
                    res = left + right;
                }
                else if (token == "-")
                {
                    res = left - right;
                }
                else if (token == "*")
                {
                    res = left * right;
                }
                else if (token == "/")
                {
                    res = left / right;
                }

                nums.push(res);
            }
            else
            {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
