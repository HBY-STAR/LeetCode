/*
 * @lc app=leetcode.cn id=134 lang=cpp
 * @lcpr version=30204
 *
 * [134] 加油站
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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int currentSum = 0, sum = 0, ans = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            int x = gas[i] - cost[i];
            sum += x;
            currentSum += x;
            if (currentSum < 0)
            {
                ans = i + 1;
                currentSum = 0;
            }
        }
        return sum < 0 ? -1 : ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n[3,4,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[3,4,3]\n
// @lcpr case=end

 */
