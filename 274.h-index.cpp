/*
 * @lc app=leetcode.cn id=274 lang=cpp
 * @lcpr version=30204
 *
 * [274] H 指数
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
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());

        int res = 0;
        for (int i = citations.size() - 1; i >= 0; i--)
        {
            if (citations[i] >= res + 1)
            {
                res++;
            }
            else
            {
                break;
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,0,6,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

 */
