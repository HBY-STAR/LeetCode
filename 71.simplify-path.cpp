/*
 * @lc app=leetcode.cn id=71 lang=cpp
 * @lcpr version=30204
 *
 * [71] 简化路径
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
    string simplifyPath(string path)
    {
        string result = "";
        vector<string> path_words;
        for (int i = 0; i < path.size(); i++)
        {
            string word = "";
            while (i < path.size() && path[i] == '/')
            {
                i++;
            }

            while (i < path.size() && path[i] != '/')
            {
                word += path[i];
                i++;
            }

            if (word != "")
            {
                if (word == "..")
                {
                    if (path_words.size() > 0)
                    {
                        path_words.pop_back();
                    }
                }
                else if (word == ".")
                {
                    continue;
                }
                else
                {
                    path_words.push_back(word);
                }
            }
        }

        for (int i = 0; i < path_words.size(); i++)
        {
            result += "/";
            result += path_words[i];
        }

        if(result == ""){
            return "/";
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "/home/"\n
// @lcpr case=end

// @lcpr case=start
// "/home//foo/"\n
// @lcpr case=end

// @lcpr case=start
// "/home/user/Documents/../Pictures"\n
// @lcpr case=end

// @lcpr case=start
// "/../"\n
// @lcpr case=end

// @lcpr case=start
// "/.../a/../b/c/../d/./"\n
// @lcpr case=end

 */
