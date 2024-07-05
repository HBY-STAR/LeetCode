/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=30117
 *
 * [6] Z 字形变换
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
class Solution {
public:
    string convert(string s, int numRows) {
        int loop = numRows + max(numRows-2,0);
        int Len = s.size();

        string result;
        int temp=0;

        for(int i=0;i<numRows;i++){
            temp=i;
            if(i==0||i==numRows-1){
                while(temp<Len){
                    result.push_back(s[temp]);
                    temp+=loop;
                }
            }else{
                while(temp<Len){
                    if(temp<Len){
                        result.push_back(s[temp]);
                    }
                    if(temp+(numRows-1-i)*2<Len){
                        result.push_back(s[temp+(numRows-1-i)*2]);
                    }
                    temp+=loop;
                }
            }
        }

        return result;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */

