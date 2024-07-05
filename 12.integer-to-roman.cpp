/*
 * @lc app=leetcode.cn id=12 lang=cpp
 * @lcpr version=30117
 *
 * [12] 整数转罗马数字
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
    string intToRoman(int num)
    {
        char romanChars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int romanValues[] = {1, 5, 10, 50, 100, 500, 1000};

        string result;
        result.reserve(20);

        for (int i = 6; i >= 0; i -= 2)
        {
            int temp = num / romanValues[i];
            if (temp > 0)
            {
                if (temp == 4)
                {
                    result.append(1, romanChars[i]);
                    result.append(1, romanChars[i + 1]);
                }
                else if (temp == 9)
                {
                    result.append(1, romanChars[i]);
                    result.append(1, romanChars[i + 2]);
                }
                else if (temp > 0 && temp < 4)
                {
                    result.append(temp, romanChars[i]);
                }
                else
                {
                    result.append(1, romanChars[i + 1]);
                    result.append(temp - 5, romanChars[i]);
                }

                num -= temp * romanValues[i];
            }
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

// @lcpr case=start
// 58\n
// @lcpr case=end

// @lcpr case=start
// 1994\n
// @lcpr case=end

 */

int main()
{
    int number = 1994;
    Solution solution;
    std::string romanNumeral = solution.intToRoman(number);
    std::cout << "Roman numeral of " << number << " is: " << romanNumeral << std::endl;
    return 0;
}