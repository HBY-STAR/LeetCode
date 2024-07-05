/*
 * @lc app=leetcode.cn id=58 lang=cpp
 * @lcpr version=30118
 *
 * [58] 最后一个单词的长度
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
    int lengthOfLastWord(string s)
    {
        int Len = s.size();

        int result = 0;
        bool first = true;

        for (int i = Len - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (first)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                first = false;
                result++;
            }
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */
