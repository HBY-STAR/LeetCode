/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30204
 *
 * [155] 最小栈
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
class MinStack
{
public:
    std::stack<int> m_stack;
    std::stack<int> min_stack;

    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int val)
    {
        m_stack.push(val);

        if (val <= min_stack.top())
        {
            min_stack.push(val);
        }
    }

    void pop()
    {
        if (m_stack.top() == min_stack.top())
        {
            min_stack.pop();
        }

        m_stack.pop();
    }

    int top()
    {
        return m_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */
