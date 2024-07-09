/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30204
 *
 * [23] 合并 K 个升序链表
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *res = nullptr;
        ListNode *tail = nullptr;

        if (lists.empty())
        {
            return res;
        }

        int listNum = lists.size();
        int countEmpty = 0;

        ListNode *p[listNum];
        for (int i = 0; i < listNum; i++)
        {
            p[i] = lists[i];
        }

        int min = INT32_MAX;
        int minIndex = 0;

        while (countEmpty < listNum)
        {
            min = INT32_MAX;
            minIndex = 0;

            for (int i = 0; i < listNum; i++)
            {
                if (p[i] != nullptr)
                {
                    if (min > p[i]->val)
                    {
                        min = p[i]->val;
                        minIndex = i;
                    }
                }
            }

            if(p[minIndex] == nullptr){
                break;
            }

            ListNode *temp = new ListNode(min, nullptr);
            if (res == nullptr)
            {
                res = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }

            p[minIndex] = p[minIndex]->next;
            if(p[minIndex] == nullptr){
                countEmpty++;
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */
