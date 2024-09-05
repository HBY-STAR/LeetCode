/*
 * @lc app=leetcode.cn id=200 lang=cpp
 * @lcpr version=30204
 *
 * [200] 岛屿数量
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
    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        vector<vector<bool>> mark(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                res += int(dfs(grid, mark, i, j));
            }
        }

        return res;
    }

    bool dfs(vector<vector<char>> &grid, vector<vector<bool>> &mark, int i, int j)
    {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !mark[i][j] && grid[i][j] == '1')
        {
            mark[i][j] = true;
            dfs(grid, mark, i + 1, j);
            dfs(grid, mark, i - 1, j);
            dfs(grid, mark, i, j + 1);
            dfs(grid, mark, i, j - 1);
            return true;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]\n
// @lcpr case=end

// @lcpr case=start
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]\n
// @lcpr case=end

 */
