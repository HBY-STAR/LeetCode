/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
        {
            return res;
        }

        unordered_map<int, vector<char>> table;
        table[2] = {'a', 'b', 'c'};
        table[3] = {'d', 'e', 'f'};
        table[4] = {'g', 'h', 'i'};
        table[5] = {'j', 'k', 'l'};
        table[6] = {'m', 'n', 'o'};
        table[7] = {'p', 'q', 'r', 's'};
        table[8] = {'t', 'u', 'v'};
        table[9] = {'w', 'x', 'y', 'z'};

        vector<int> index;
        for (int i = 0; i < digits.size(); i++)
        {
            index.push_back(digits[i] - '0');
        }

        int resSize = 1;
        for (int i = 0; i < index.size(); i++)
        {
            resSize *= table[index[i]].size();
        }

        for (int i = 0; i < resSize; i++)
        {
            string temp;
            int tempIndex = i;
            for (int j = 0; j < index.size(); j++)
            {
                temp += table[index[j]][tempIndex % table[index[j]].size()];
                tempIndex /= table[index[j]].size();
            }
            res.push_back(temp);
        }
        
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
