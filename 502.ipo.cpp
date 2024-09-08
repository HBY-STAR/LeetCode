/*
 * @lc app=leetcode.cn id=502 lang=cpp
 * @lcpr version=30204
 *
 * [502] IPO
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
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        // 优先队列，按启动资本排序（小顶堆）
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapital;
        // 优先队列，按利润排序（大顶堆）
        priority_queue<int> maxProfit;

        // 初始化，将所有项目按启动资本排序，存入minCapital
        for (int i = 0; i < profits.size(); i++)
        {
            minCapital.emplace(capital[i], profits[i]);
        }

        // 进行最多k次投资
        for (int i = 0; i < k; i++)
        {
            // 将所有启动资本小于等于当前资本的项目转移到maxProfit
            while (!minCapital.empty() && minCapital.top().first <= w)
            {
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            // 如果没有可投资的项目，退出循环
            if (maxProfit.empty())
            {
                break;
            }

            // 选择利润最大的项目进行投资，更新当前资本
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n0\n[1,2,3]\n[0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// 3\n0\n[1,2,3]\n[0,1,2]\n
// @lcpr case=end

 */
