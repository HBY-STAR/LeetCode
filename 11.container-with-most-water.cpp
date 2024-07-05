/*
 * @lc app=leetcode.cn id=11 lang=cpp
 * @lcpr version=30117
 *
 * [11] 盛最多水的容器
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
    int maxArea(vector<int> &height)
    {
        int Len = height.size();
        int result = 0;

        int maxHeight = 0;
        int maxAt = 0;

        int partMax = 0;

        vector<pair<int, int>> lines;

        for (int i = 0; i < Len; i++)
        {
            if (height[i] > maxHeight)
            {
                maxHeight = height[i];
                maxAt = i;
            }
        }

        lines.push_back({height[0], 0});
        partMax = height[0];
        for (int i = 1; i < maxAt; i++)
        {
            if (height[i] <= partMax)
            {
                continue;
            }
            else
            {
                lines.push_back({height[i], i});
                partMax = height[i];
            }

            if (partMax == maxHeight)
            {
                break;
            }
        }

        int lastMaxAt = 0;
        for (int i = maxAt; i < Len; i++)
        {
            if (height[i] == maxHeight)
            {
                lines.push_back({height[i], i});
                lastMaxAt = i;
            }
        }

        lines.push_back({height[Len - 1], Len - 1});
        partMax = height[Len - 1];
        for (int i = Len - 1; i > lastMaxAt; i--)
        {
            if (height[i] <= partMax)
            {
                continue;
            }
            else
            {
                lines.push_back({height[i], i});
                partMax = height[i];
            }
        }

        int temp = 0;
        int newLen = lines.size();
        for (int i = 0; i < newLen; i++)
        {
            for (int j = i + 1; j < newLen; j++)
            {
                temp = min(lines[i].first, lines[j].first) * abs(lines[i].second - lines[j].second);

                if (temp > result)
                {
                    result = temp;
                }
            }
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,8,6,2,5,4,8,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */
