/*
 * @lc app=leetcode.cn id=57 lang=cpp
 * @lcpr version=30204
 *
 * [57] 插入区间
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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;

        int len = intervals.size();

        vector<int> coverIndex;

        for (int i = 0; i < len; i++)
        {
            if (newInterval[1] >= intervals[i][0] && newInterval[0] <= intervals[i][1])
            {
                coverIndex.push_back(i);
            }
        }

        if (coverIndex.size() == 0)
        {
            intervals.push_back(newInterval);
            sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });
            return intervals;
        }

        int minIndex = coverIndex[0];
        int maxIndex = coverIndex[coverIndex.size() - 1];

        for (int i = 0; i < len; i++)
        {
            if (i >= minIndex && i <= maxIndex)
            {
                res.push_back({min(intervals[minIndex][0], newInterval[0]), max(intervals[maxIndex][1], newInterval[1])});
                i = maxIndex;
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

 */
