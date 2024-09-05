/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=30204
 *
 * [167] 两数之和 II - 输入有序数组
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
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        for (int i = 0; i < numbers.size(); i++)
        {
            int j = binSearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            if (j != -1)
            {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
        }

        return res;
    }

    int binSearch(vector<int> &numbers, int l, int r, int target)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (numbers[m] == target)
            {
                return m;
            }
            else if (numbers[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */
