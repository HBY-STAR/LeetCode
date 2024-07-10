/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30204
 *
 * [48] 旋转图像
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
    void rotate(vector<vector<int>> &matrix)
    {
        // 转置后将每一行倒转

        int lineNum = matrix.size();
        int lineSize = matrix[0].size();

        if (lineNum == 1)
        {
            return;
        }

        // 转置
        for (int i = 0; i < lineNum; i++)
        {
            for (int j = i + 1; j < lineSize; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // 倒转
        for (int i = 0; i < lineNum; i++)
        {
            int middle = lineSize / 2;
            for (int j = 0; j < middle; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][lineSize - j - 1];
                matrix[i][lineSize - j - 1] = temp;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */
