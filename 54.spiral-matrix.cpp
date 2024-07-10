/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int lineNum = matrix.size();
        int lineSize = matrix[0].size();
        int resLen = lineNum * lineSize;

        bool up = false;
        bool down = false;
        bool left = false;
        bool right = true;

        int posX = 0;
        int posY = 0;

        vector<vector<bool>> remain;
        for (int i = 0; i < lineNum; i++)
        {
            vector<bool> temp;
            for (int j = 0; j < lineSize; j++)
            {
                temp.push_back(true);
            }
            remain.push_back(temp);
        }

        while (res.size() < resLen)
        {
            if (posX >= 0 && posX < lineNum && posY >= 0 && posY < lineSize && remain[posX][posY])
            {
                res.push_back(matrix[posX][posY]);
                remain[posX][posY] = false;

                // move to next
                if (up)
                {
                    posX -= 1;
                }
                else if (down)
                {
                    posX += 1;
                }
                else if (left)
                {
                    posY -= 1;
                }
                else
                {
                    posY += 1;
                }
            }
            else
            {
                if (up)
                {
                    up = false;
                    right = true;

                    posX += 1;
                    posY += 1;
                }
                else if (down)
                {
                    down = false;
                    left = true;
                    posX -= 1;
                    posY -= 1;
                }
                else if (left)
                {
                    left = false;
                    up = true;

                    posX -= 1;
                    posY += 1;
                }
                else
                {
                    right = false;
                    down = true;
                    posX += 1;
                    posY -= 1;
                }
            }
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */
