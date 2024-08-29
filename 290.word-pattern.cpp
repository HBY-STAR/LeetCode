/*
 * @lc app=leetcode.cn id=290 lang=cpp
 * @lcpr version=30204
 *
 * [290] 单词规律
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
#include <sstream>
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
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        vector<string> words = splitStringBySpace(s);

        if (pattern.size() != words.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < pattern.size(); i++)
            {
                if (map1.count(pattern[i]))
                {
                    if (map1[pattern[i]] != words[i])
                    {
                        return false;
                    }
                }
                else
                {
                    map1[pattern[i]] = words[i];
                }
            }

            for (int i = 0; i < pattern.size(); i++)
            {
                if (map2.count(words[i]))
                {
                    if (map2[words[i]] != pattern[i])
                    {
                        return false;
                    }
                }
                else
                {
                    map2[words[i]] = pattern[i];
                }
            }

            return true;
        }
    }

    vector<string> splitStringBySpace(const string &s)
    {
        vector<string> words;
        istringstream iss(s);
        string word;
        while (iss >> word)
        {
            words.push_back(word);
        }
        return words;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */
