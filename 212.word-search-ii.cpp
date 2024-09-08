/*
 * @lc app=leetcode.cn id=212 lang=cpp
 * @lcpr version=30204
 *
 * [212] 单词搜索 II
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
    struct TrieNode
    {
        TrieNode *children[26] = {nullptr};
        string word = "";
    };

    void insert(TrieNode *root, const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children[c - 'a'])
            {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->word = word;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (const string &word : words)
        {
            insert(root, word);
        }

        vector<string> res;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> mark(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(board, mark, i, j, root, res);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>> &board, vector<vector<bool>> &mark, int i, int j, TrieNode *node, vector<string> &res)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || mark[i][j])
        {
            return;
        }

        char c = board[i][j];
        if (!node->children[c - 'a'])
        {
            return;
        }

        node = node->children[c - 'a'];
        if (!node->word.empty())
        {
            res.push_back(node->word);
            node->word = "";
        }

        mark[i][j] = true;
        dfs(board, mark, i + 1, j, node, res);
        dfs(board, mark, i - 1, j, node, res);
        dfs(board, mark, i, j + 1, node, res);
        dfs(board, mark, i, j - 1, node, res);
        mark[i][j] = false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["c","d"]]\n["abcb"]\n
// @lcpr case=end

 */
