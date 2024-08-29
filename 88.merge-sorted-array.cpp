/*
 * @lc app=leetcode.cn id=88 lang=cpp
 * @lcpr version=30204
 *
 * [88] 合并两个有序数组
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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp;
        for (int i = 0; i < m; i++)
        {
            temp.push_back(nums1[i]);
        }

        int a = 0, b = 0;

        while (a < temp.size() && b < nums2.size())
        {
            if (temp[a] < nums2[b])
            {
                nums1[a + b] = temp[a];
                a++;
            }
            else
            {
                nums1[a + b] = nums2[b];
                b++;
            }
        }

        while (a < temp.size())
        {
            nums1[a + b] = temp[a];
            a++;
        }

        while (b < nums2.size())
        {
            nums1[a + b] = nums2[b];
            b++;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,0,0,0]\n3\n[2,5,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n[]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0]\n0\n[1]\n1\n
// @lcpr case=end

 */
