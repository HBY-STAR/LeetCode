/*
 * @lc app=leetcode.cn id=380 lang=cpp
 * @lcpr version=30204
 *
 * [380] O(1) 时间插入、删除和获取随机元素
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
class RandomizedSet
{
public:
    unordered_map<int, int> set;
    vector<int> set_array;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (set.count(val))
        {
            return false;
        }
        else
        {
            set_array.push_back(val);
            set[val] = set_array.size() - 1;
            return true;
        }
    }

    bool remove(int val)
    {
        if (set.count(val))
        {
            int last = set_array.back();
            set_array[set[val]] = last;
            set_array.pop_back();
            set[last] = set[val];
            set.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom()
    {
        int randomIndex = rand() % set_array.size();
        return set_array[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
