/*
 * @lc app=leetcode.cn id=67 lang=cpp
 * @lcpr version=30118
 *
 * [67] 二进制求和
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
    string addBinary(string a, string b)
    {
        int Len1 = a.size(), Len2 = b.size();

        int i = Len1 - 1, j = Len2 - 1;
        int add = 0;
        string result;

        while (i > -1 || j > -1)
        {
            int m = 0, n = 0;
            if (i > -1)
            {
                m = int(a[i] - 48);
            }
            if (j > -1)
            {
                n = int(b[j] - 48);
            }

            int sum = add + m + n;

            if (sum >= 2)
            {
                char temp = char(sum + 48 - 2);
                add = 1;
                result = temp + result;
            }
            else
            {
                char temp = char(sum + 48);
                add = 0;
                result = temp + result;
            }
            i--;
            j--;
        }
        if (add == 1)
        {
            result = '1' + result;
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "11"\n"1"\n
// @lcpr case=end

// @lcpr case=start
// "1010"\n"1011"\n
// @lcpr case=end

 */
