/*
 * @lc app=leetcode.cn id=149 lang=cpp
 * @lcpr version=30204
 *
 * [149] 直线上最多的点数
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
#include <string>
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }

    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
        {
            return n;
        }
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (ret >= n - i || ret > n / 2)
            {
                break;
            }
            unordered_map<int, int> mp;
            for (int j = i + 1; j < n; j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                if (x == 0)
                {
                    y = 1;
                }
                else if (y == 0)
                {
                    x = 1;
                }
                else
                {
                    if (y < 0)
                    {
                        x = -x;
                        y = -y;
                    }
                    int gcdXY = gcd(abs(x), abs(y));
                    x /= gcdXY, y /= gcdXY;
                }
                mp[y + x * 20001]++;
            }
            int maxn = 0;
            for (auto &[_, num] : mp)
            {
                maxn = max(maxn, num + 1);
            }
            ret = max(ret, maxn);
        }
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1],[2,2],[3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]\n
// @lcpr case=end

 */
