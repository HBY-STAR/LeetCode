/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30118
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        ListNode *result = new ListNode();
        ListNode *temp = result;

        while (list1 != nullptr || list2 != nullptr)
        {
            if (list1 == nullptr)
            {
                temp->val = list2->val;
                list2 = list2->next;
            }
            else if (list2 == nullptr)
            {
                temp->val = list1->val;
                list1 = list1->next;
            }
            else if (list1->val > list2->val)
            {
                temp->val = list2->val;
                list2 = list2->next;
            }
            else
            {
                temp->val = list1->val;
                list1 = list1->next;
            }

            if (list1 != nullptr || list2 != nullptr)
            {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */
