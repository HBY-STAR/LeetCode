/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=30204
 *
 * [208] 实现 Trie (前缀树)
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
class Trie
{
public:
    struct TreeNode
    {
        char val;
        bool isEnd;
        list<TreeNode *> nodes;
        TreeNode(char x, bool y) : val(x), isEnd(y) {}
    };

    TreeNode *root;

    Trie()
    {
        root = new TreeNode(0, false);
    }

    void insert(string word)
    {
        TreeNode *temp = root;
        for (auto &w : word)
        {
            TreeNode *findNode = nullptr;
            for (auto node : temp->nodes)
            {
                if (node->val == w)
                {
                    findNode = node;
                    break;
                }
            }

            if (findNode)
            {
                temp = findNode;
            }
            else
            {
                TreeNode *newNode = new TreeNode(w, false);
                temp->nodes.push_back(newNode);
                temp = newNode;
            }
        }

        temp->isEnd = true;
    }

    bool search(string word)
    {
        bool find = true;
        TreeNode *temp = root;
        for (auto &w : word)
        {
            TreeNode *findNode = nullptr;
            for (auto node : temp->nodes)
            {
                if (node->val == w)
                {
                    findNode = node;
                    break;
                }
            }

            if (findNode)
            {
                temp = findNode;
            }
            else
            {
                find = false;
                break;
            }
        }

        return find && temp->isEnd;
    }

    bool startsWith(string prefix)
    {
        bool find = true;
        TreeNode *temp = root;
        for (auto &w : prefix)
        {
            TreeNode *findNode = nullptr;
            for (auto node : temp->nodes)
            {
                if (node->val == w)
                {
                    findNode = node;
                    break;
                }
            }

            if (findNode)
            {
                temp = findNode;
            }
            else
            {
                find = false;
                break;
            }
        }

        return find;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
