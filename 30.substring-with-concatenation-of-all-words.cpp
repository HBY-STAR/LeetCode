/*
 * @lc app=leetcode.cn id=30 lang=cpp
 * @lcpr version=30204
 *
 * [30] 串联所有单词的子串
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
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ret;
        if (s.empty() || words.empty())
            return ret;

        unordered_map<string, int> wordCount;
        for (const auto &word : words)
        {
            ++wordCount[word];
        }

        int wordNum = words.size();
        int wordLen = words[0].size();
        int windowLen = wordNum * wordLen;

        for (int i = 0; i < wordLen; ++i)
        {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;
            while (right + wordLen <= s.size())
            {
                string word = s.substr(right, wordLen);
                right += wordLen;
                if (wordCount.find(word) != wordCount.end())
                {
                    ++seen[word];
                    ++count;
                    while (seen[word] > wordCount[word])
                    {
                        string leftWord = s.substr(left, wordLen);
                        --seen[leftWord];
                        --count;
                        left += wordLen;
                    }
                    if (count == wordNum)
                        ret.push_back(left);
                }
                else
                {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "barfoothefoobarman"\n["foo","bar"]\n
// @lcpr case=end

// @lcpr case=start
// "wordgoodgoodgoodbestword"\n["word","good","best","word"]\n
// @lcpr case=end

// @lcpr case=start
// "barfoofoobarthefoobarman"\n["bar","foo","the"]\n
// @lcpr case=end

 */
