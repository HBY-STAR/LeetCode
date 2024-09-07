/*
 * @lc app=leetcode.cn id=399 lang=cpp
 * @lcpr version=30204
 *
 * [399] 除法求值
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
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        vector<double> res;
        unordered_map<string, vector<pair<string, double>>> graph;
        unordered_map<string, bool> mark;

        for (int i = 0; i < equations.size(); i++)
        {
            graph[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(make_pair(equations[i][0], 1.0 / values[i]));
            mark[equations[i][0]] = false;
            mark[equations[i][1]] = false;
        }

        for (auto &q : queries)
        {

            if (q[0] == q[1] && graph.count(q[0]))
            {
                res.push_back(1.0);
            }
            else
            {
                double compute = -1.0;
                dfs(q[0], q[1], graph, mark, 1.0, compute);
                res.push_back(compute);
            }
        }

        return res;
    }

    void dfs(string &start, string &end, unordered_map<string, vector<pair<string, double>>> &graph, unordered_map<string, bool> &mark, double tempCompute, double &compute)
    {
        if (graph.count(start) && compute == -1.0)
        {
            mark[start] = true;
            for (auto &out : graph[start])
            {
                if (out.first == end)
                {
                    compute = tempCompute * out.second;
                }
                else if (!mark[out.first])
                {
                    dfs(out.first, end, graph, mark, tempCompute * out.second, compute);
                }
            }
            mark[start] = false;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]\n
// @lcpr case=end

 */
