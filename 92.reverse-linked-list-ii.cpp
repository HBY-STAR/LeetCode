/*
 * @lc app=leetcode.cn id=92 lang=cpp
 * @lcpr version=30204
 *
 * [92] 反转链表 II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *p, q;
        ListNode *temp = head;
        int count = 0;
        stack<int> inverse;
        while (temp)
        {
            count++;
            if (count >= left && count <= right)
            {
                inverse.push(temp->val);
            }
            temp = temp->next;
        }
        temp = head;
        count = 0;
        while (temp)
        {
            count++;
            if (count >= left && count <= right)
            {
                temp->val = inverse.top();
                inverse.pop();
            }
            temp = temp->next;
        }

        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */
