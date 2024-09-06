/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=30204
 *
 * [207] 课程表
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(numCourses, 0);
        unordered_map<int, vector<int>> graph;

        // 构建图和入度数组
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }

        queue<int> q;
        // 将所有入度为 0 的节点入队
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            count++;

            for (int nextCourse : graph[course])
            {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0)
                {
                    q.push(nextCourse);
                }
            }
        }

        return count == numCourses;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */
