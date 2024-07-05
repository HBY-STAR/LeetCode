// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30117
 *
 * [4] 寻找两个正序数组的中位数
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
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans; // 用来存储合并后的有序数组
        int n1 = 0, n2 = 0; // 分别表示遍历 nums1 和 nums2 的指针
 
        // 合并两个有序数组，直到其中一个数组的所有元素都被处理完
        while (n1 < nums1.size() && n2 < nums2.size()) {
            // 比较当前指针位置的元素，将较小的元素添加到 ans 中，并将相应指针向后移动一位
            ans.push_back(nums1[n1] >= nums2[n2] ? nums2[n2++] : nums1[n1++]);
        }
 
        // 将剩余未处理的元素添加到 ans 中
        for (; n1 < nums1.size(); n1++) {
            ans.push_back(nums1[n1]);
        }
 
        for (; n2 < nums2.size(); n2++) {
            ans.push_back(nums2[n2]);
        }
 
        int n = ans.size() - 1;
        int medianIndex = n / 2; // 计算中位数的索引位置
 
        // 如果 ans 的长度为奇数，返回中间的元素；如果长度为偶数，返回中间两个元素的平均值
        return (ans[medianIndex] + ans[n - medianIndex]) / 2.0;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */
