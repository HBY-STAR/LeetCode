/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30117
 *
 * [3] 无重复字符的最长子串
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
class Solution {
public:
    // 使用哈希表 
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hashtable;

        int maxLen = 0;

        for (int i = 0; i < s.size(); ++i) {
            auto it = hashtable.find(s[i]);
            
            //若找到
            if (it != hashtable.end()) {
                std::vector<char> toBeDeleted;

                for (const auto& pair : hashtable) {
                    if (pair.second <= hashtable[s[i]]) {
                        toBeDeleted.push_back(pair.first);
                    }
                }

                for (const auto& key : toBeDeleted) {
                    hashtable.erase(key);
                }

                hashtable[s[i]] = i;
            }

            //若未找到
            else{
                hashtable[s[i]] = i;
                if(hashtable.size() > maxLen)
                    maxLen = hashtable.size();
            }
            
        }

        return maxLen;
    }

};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

