/*
 * @lc app=leetcode.cn id=73 lang=cpp
 * @lcpr version=30204
 *
 * [73] 矩阵置零
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
    void setZeroes(vector<vector<int>> &matrix)
    {
        int x_len = matrix.size();
        int y_len = matrix[0].size();
        unordered_map<int, bool> a;
        unordered_map<int, bool> b;

        for (int i = 0; i < x_len; i++)
        {
            for (int j = 0; j < y_len; j++)
            {
                if (matrix[i][j] == 0)
                {
                    a[i] = true;
                    b[j] = true;
                }
            }
        }

        for (const auto &pair : a)
        {
            for (int j = 0; j < y_len; j++)
            {
                matrix[pair.first][j] = 0;
            }
        }

        for (const auto &pair : b)
        {
            for (int i = 0; i < x_len; i++)
            {
                matrix[i][pair.first] = 0;
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]]\n
// @lcpr case=end

 */
