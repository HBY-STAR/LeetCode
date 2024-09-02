/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30204
 *
 * [138] 随机链表的复制
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
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }

        Node *temp = head;
        unordered_map<Node *, int> node2Index;
        int index = 0;
        while (temp)
        {
            node2Index[temp] = index;

            temp = temp->next;
            index++;
        }

        Node *copyHead = new Node(head->val);
        Node *copyTemp = copyHead;
        temp = head->next;
        index = 0;
        unordered_map<int, Node *> index2Node;
        index2Node[index] = copyHead;

        while (temp)
        {
            Node *copyNode = new Node(temp->val);
            index++;
            index2Node[index] = copyNode;
            copyTemp->next = copyNode;

            copyTemp = copyTemp->next;
            temp = temp->next;
        }

        temp = head;
        copyTemp = copyHead;
        while (temp)
        {
            if (temp->random)
            {
                copyTemp->random = index2Node[node2Index[temp->random]];
            }
            temp = temp->next;
            copyTemp = copyTemp->next;
        }

        return copyHead;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */
