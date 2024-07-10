/*
 * @lc app=leetcode.cn id=50 lang=cpp
 * @lcpr version=30204
 *
 * [50] Pow(x, n)
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
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            double res = 1;
            bool negative = false;

            // 处理特殊情况
            if (n == INT32_MIN)
            {
                negative = true;
                n = INT32_MAX;
                res = x;
            }
            else if (n < 0)
            {
                negative = true;
                n = -n;
            }

            unordered_map<int, double> map;
            map[1] = x;

            int maxIndex = 1;
            for (int i = 2; i < n && i < INT32_MAX / 2; i = i * 2)
            {
                maxIndex = i;
                map[i] = map[i / 2] * map[i / 2];
            }

            int left = n;
            while (left > 0)
            {
                if (left >= maxIndex)
                {
                    left -= maxIndex;
                    res *= map[maxIndex];
                }
                else
                {
                    maxIndex /= 2;
                }
            }

            if (negative)
            {
                return 1 / res;
            }
            else
            {
                return res;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2.00000\n10\n
// @lcpr case=end

// @lcpr case=start
// 2.10000\n3\n
// @lcpr case=end

// @lcpr case=start
// 2.00000\n-2\n
// @lcpr case=end

 */
