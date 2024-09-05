/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30204
 *
 * [151] 反转字符串中的单词
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
    vector<string> words;
    void splitString(const string &str)
    {
        istringstream iss(str);

        string word;
        while (iss >> word)
        {
            words.push_back(word);
        }
    }

    string reverseWords(string s)
    {
        words.clear();
        splitString(s);

        string res;
        for (int i = words.size() - 1; i >= 0; i--)
        {
            res += words[i];
            if (i != 0)
            {
                res += " ";
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */
