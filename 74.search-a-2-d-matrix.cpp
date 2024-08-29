/*
 * @lc app=leetcode.cn id=74 lang=cpp
 * @lcpr version=30204
 *
 * [74] 搜索二维矩阵
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
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int lineNum = matrix.size();
        int lineSize = matrix[0].size();

        if (target < matrix[0][0] || target > matrix[lineNum - 1][lineSize - 1])
        {
            return false;
        }

        if (target == matrix[0][0] || target == matrix[lineNum - 1][lineSize - 1])
        {
            return true;
        }

        int lineIndex = 0;
        for (int i = 0; i < lineNum; i++)
        {
            if (matrix[i][0] <= target)
            {
                lineIndex = i;
            }
            else
            {
                break;
            }
        }

        int linePos = 0;
        for (int i = 0; i < lineSize; i++)
        {
            if (matrix[lineIndex][i] <= target)
            {
                linePos = i;
            }
            else
            {
                break;
            }
        }

        if (matrix[lineIndex][linePos] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n13\n
// @lcpr case=end

 */
