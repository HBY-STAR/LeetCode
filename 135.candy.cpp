/*
 * @lc app=leetcode.cn id=135 lang=cpp
 * @lcpr version=30204
 *
 * [135] 分发糖果
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
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // 从左到右扫描
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
        }

        // 从右到左扫描
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                right[i] = right[i + 1] + 1;
            }
        }

        // 计算结果
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += max(left[i], right[i]);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

 */
