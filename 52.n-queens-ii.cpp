/*
 * @lc app=leetcode.cn id=52 lang=cpp
 * @lcpr version=30204
 *
 * [52] N 皇后 II
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
    int res = 0;
    int totalNQueens(int n)
    {
        res = 0;
        vector<vector<bool>> currentStatus;

        for (int i = 0; i < n; i++)
        {
            vector<bool> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(true);
            }
            currentStatus.push_back(temp);
        }

        backtrack(currentStatus, 0, n);

        return res;
    }

    void backtrack(vector<vector<bool>> currentStatus, int currentLine, int n)
    {
        if (currentLine == n)
        {
            res++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (currentStatus[currentLine][i])
            {
                vector<vector<bool>> nowStatus = currentStatus;
                int nowLine = currentLine + 1;

                // 更新列状态
                for (int x = currentLine + 1, y = i; x >= 0 && x < n && y >= 0 && y < n; x++)
                {
                    nowStatus[x][y] = false;
                }

                // 更新 / 对角状态
                for (int x = currentLine + 1, y = i - 1; x >= 0 && x < n && y >= 0 && y < n; x++, y--)
                {
                    nowStatus[x][y] = false;
                }

                // 更新 \ 对角状态
                for (int x = currentLine + 1, y = i + 1; x >= 0 && x < n && y >= 0 && y < n; x++, y++)
                {
                    nowStatus[x][y] = false;
                }

                backtrack(nowStatus, nowLine, n);
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
