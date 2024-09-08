/*
 * @lc app=leetcode.cn id=127 lang=cpp
 * @lcpr version=30204
 *
 * [127] 单词接龙
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
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;

    void addWord(string &word)
    {
        if (!wordId.count(word))
        {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string &word)
    {
        addWord(word);
        int id1 = wordId[word];
        for (char &it : word)
        {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (string &word : wordList)
        {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord))
        {
            return 0;
        }
        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while (!que.empty())
        {
            int x = que.front();
            que.pop();
            if (x == endId)
            {
                return dis[endId] / 2 + 1;
            }
            for (int &it : edge[x])
            {
                if (dis[it] == INT_MAX)
                {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
};
// class Solution
// {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string> &wordList)
//     {
//         unordered_map<string, vector<string>> wordMap;

//         for (int i = 0; i < wordList.size(); i++)
//         {
//             for (int j = 0; j < wordList.size(); j++)
//             {
//                 if (i != j && checkOk(wordList[i], wordList[j]))
//                 {
//                     wordMap[wordList[i]].push_back(wordList[j]);
//                     wordMap[wordList[j]].push_back(wordList[i]);
//                 }
//             }
//         }
//         if (wordMap[endWord].empty())
//         {
//             return 0;
//         }
//         if (wordMap[beginWord].empty())
//         {
//             for (int i = 0; i < wordList.size(); i++)
//             {
//                 if (checkOk(wordList[i], beginWord))
//                 {
//                     wordMap[beginWord].push_back(wordList[i]);
//                 }
//             }
//         }

//         int minRes = INT_MAX;
//         queue<string> q;
//         q.push(beginWord);
//         int curLevel = 1;
//         unordered_set<string> visited;
//         while (!q.empty() && minRes == INT_MAX)
//         {
//             curLevel++;

//             int size = q.size();
//             for (int i = 0; i < size; i++)
//             {
//                 string inNode = q.front();
//                 visited.insert(inNode);
//                 q.pop();
//                 for (auto outNode : wordMap[inNode])
//                 {
//                     if (!visited.count(outNode))
//                     {
//                         if (outNode == endWord)
//                         {
//                             minRes = min(minRes, curLevel);
//                             break;
//                         }
//                         else
//                         {
//                             q.push(outNode);
//                         }
//                     }
//                 }
//             }
//         }

//         return minRes == INT_MAX ? 0 : minRes;
//     }

//     bool checkOk(string &a, string &b)
//     {
//         int count = 0;
//         for (int i = 0; i < a.size(); i++)
//         {
//             if (a[i] != b[i])
//             {
//                 count++;
//             }
//         }

//         return count == 1;
//     }
// };
// @lc code=end

/*
// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]\n
// @lcpr case=end

// @lcpr case=start
// "hit"\n"cog"\n["hot","dot","dog","lot","log"]\n
// @lcpr case=end

 */
