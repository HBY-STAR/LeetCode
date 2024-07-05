/*
 * @lc app=leetcode.cn id=66 lang=cpp
 * @lcpr version=30118
 *
 * [66] 加一
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
    vector<int> plusOne(vector<int> &digits)
    {
        int Len = digits.size();

        bool all_nine = true;

        for (int i = 0; i < Len; i++)
        {
            if (digits[i] != 9)
            {
                all_nine = false;
                break;
            }
        }

        if (all_nine)
        {
            vector<int> result;
            result.push_back(1);
            for (int i = 1; i < Len + 1; i++)
            {
                result.push_back(0);
            }
            return result;
        }
        else
        {
            int add = 1;
            for (int i = Len - 1; i >= 0; i--)
            {
                digits[i] += add;
                if (digits[i] == 10)
                {
                    digits[i] = 0;
                    add = 1;
                }
                else
                {
                    add = 0;
                }
            }
            return digits;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */
