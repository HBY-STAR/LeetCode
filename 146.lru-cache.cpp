/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30204
 *
 * [146] LRU 缓存
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
class LRUCache
{
public:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> lru;
    int m_capacity;

    LRUCache(int capacity)
    {
        m_capacity = capacity;
    }

    int get(int key)
    {
        if (cache.count(key))
        {
            lru.erase(cache[key].second);
            lru.push_front(key);
            cache[key].second = lru.begin();
            return cache[key].first;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            lru.erase(cache[key].second);
        }
        else
        {
            if (cache.size() >= m_capacity)
            {
                int lru_key = lru.back();
                lru.pop_back();
                cache.erase(lru_key);
            }
        }
        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
