/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30204
 *
 * [79] 单词搜索
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
    vector<vector<bool>> mark;
    string temp;
    bool flag;

    void dfs(vector<vector<char>> &board, string &word, int i, int j, int n)
    {
        if (n == word.size())
        {
            flag = true;
            return;
        }

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || n >= word.size())
        {
            return;
        }
        if (board[i][j] == word[n] && !mark[i][j])
        {
            temp.push_back(word[n]);
            mark[i][j] = true;

            dfs(board, word, i + 1, j, n + 1);

            dfs(board, word, i, j + 1, n + 1);

            dfs(board, word, i - 1, j, n + 1);

            dfs(board, word, i, j - 1, n + 1);

            temp.pop_back();
            mark[i][j] = false;
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        flag = false;
        for (int i = 0; i < board.size(); i++)
        {
            vector<bool> temp;
            for (int j = 0; j < board[0].size(); j++)
            {
                temp.push_back(false);
            }
            mark.push_back(temp);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, word, i, j, 0);
            }
        }

        return flag;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */
