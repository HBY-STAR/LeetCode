// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30204
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverse(ListNode *first, ListNode *last)
    {
        ListNode *prev = last;
        while (first != last)
        {
            ListNode *tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        while (true)
        {
            ListNode *tail = prev;
            for (int i = 0; i < k; ++i)
            {
                tail = tail->next;
                if (!tail)
                    return dummy.next;
            }
            ListNode *next = tail->next;
            ListNode *newHead = reverse(prev->next, tail->next);
            ListNode *newTail = prev->next;
            prev->next = newHead;
            newTail->next = next;
            prev = newTail;
        }
    }
}

;
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */
