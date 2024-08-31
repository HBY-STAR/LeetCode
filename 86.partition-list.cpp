/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=30204
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *temp = new ListNode();
        temp->next = head;

        while (temp->next)
        {
            if (temp->next->val >= x)
            {
                break;
            }
            temp = temp->next;
        }

        ListNode *p = temp;
        ListNode *q = temp->next;
        bool first = true;

        temp = new ListNode();
        temp->next = q;
        while (temp->next)
        {
            if (temp->next->val < x)
            {
                ListNode *rp = temp->next;
                temp->next = temp->next->next;
                rp->next = q;
                p->next = rp;
                p = rp;

                if (q == head && first)
                {
                    head = rp;
                    first = false;
                }
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
