/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30204
 *
 * [373] 查找和最小的 K 对数字
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
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> res;

        // 定义一个最小堆，存储元素为 (i, j)
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b)
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        // 初始化堆，放入 nums1 的第一个元素和 nums2 的所有元素的组合
        for (int j = 0; j < nums2.size() && j < k; ++j)
        {
            minHeap.emplace(make_pair(0, j));
        }

        // 取出最小的 k 对数对
        while (k > 0 && !minHeap.empty())
        {
            k--;
            auto cur = minHeap.top();
            minHeap.pop();
            int i = cur.first;
            int j = cur.second;
            res.push_back({nums1[i], nums2[j]});

            if (i + 1 < nums1.size())
            {
                minHeap.emplace(make_pair(i + 1, j));
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */
