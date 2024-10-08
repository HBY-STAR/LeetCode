/*
 * @lc app=leetcode->cn id=2 lang=cpp
 * @lcpr version=30117
 *
 * [2] 两数相加
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
 * Definition for singly-linked list->
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        ListNode* trace;

        bool first = true;
        int add = 0;
        int curAddNum = 0;

        while(!(l1==nullptr && l2==nullptr)){
            
            int a = 0;
            int b = 0;

            if(l1!=nullptr)
                a = l1->val;
            if(l2!=nullptr)
                b = l2->val;

            curAddNum = a + b + add;

            if(curAddNum > 9){
                temp->val = curAddNum - 10;
                add = 1;
            }else{
                temp->val = curAddNum;
                add = 0;
            }

            if(l1!=nullptr)
                l1 = l1->next;
            if(l2!=nullptr)
                l2 = l2->next;
                
            temp->next = new ListNode();
            trace = temp;
            temp = temp->next;
        }

        if(add != 0){
            temp->val = 1;
        }

        if(temp->val == 0){
            trace->next = nullptr;
        }
        
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

