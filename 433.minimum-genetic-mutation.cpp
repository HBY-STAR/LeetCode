/*
 * @lc app=leetcode.cn id=433 lang=cpp
 * @lcpr version=30204
 *
 * [433] 最小基因变化
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
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_map<string, vector<string>> bankMap;

        for (int i = 0; i < bank.size(); i++)
        {
            for (int j = 0; j < bank.size(); j++)
            {
                if (i != j && checkOk(bank[i], bank[j]))
                {
                    bankMap[bank[i]].push_back(bank[j]);
                    bankMap[bank[j]].push_back(bank[i]);
                }
            }
        }
        if (bankMap[startGene].empty())
        {
            for (int i = 0; i < bank.size(); i++)
            {
                if (checkOk(bank[i], startGene))
                {
                    bankMap[startGene].push_back(bank[i]);
                }
            }
        }

        int minRes = INT_MAX;
        queue<string> q;
        q.push(startGene);
        int curLevel = 0;
        unordered_set<string> visited;
        while (!q.empty() && minRes == INT_MAX)
        {
            curLevel++;

            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string inNode = q.front();
                visited.insert(inNode);
                q.pop();
                for (auto outNode : bankMap[inNode])
                {
                    if (!visited.count(outNode))
                    {
                        if (outNode == endGene)
                        {
                            minRes = min(minRes, curLevel);
                            break;
                        }
                        else
                        {
                            q.push(outNode);
                        }
                    }
                }
            }
        }

        return minRes == INT_MAX ? -1 : minRes;
    }

    bool checkOk(string &a, string &b)
    {
        int count = 0;
        for (int i = 0; i < 8; i++)
        {
            if (a[i] != b[i])
            {
                count++;
            }
        }

        return count == 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]\n
// @lcpr case=end

// @lcpr case=start
// "AACCGGTT"\n"AAACGGTA"\n["AACCGGTA","AACCGCTA","AAACGGTA"]\n
// @lcpr case=end

// @lcpr case=start
// "AAAAACCC"\n"AACCCCCC"\n["AAAACCCC","AAACCCCC","AACCCCCC"]\n
// @lcpr case=end

 */
