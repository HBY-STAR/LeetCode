/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=30204
 *
 * [210] 课程表 II
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
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> res;
        queue<int> q;

        vector<int> inDegree;
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < numCourses; i++)
        {
            inDegree.push_back(0);
        }

        for (auto &p : prerequisites)
        {
            inDegree[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            res.push_back(node);
            q.pop();

            for (auto outNode : graph[node])
            {
                inDegree[outNode]--;

                if (inDegree[outNode] == 0)
                {
                    q.push(outNode);
                }
            }
        }

        if (res.size() != numCourses)
        {
            res.clear();
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */
