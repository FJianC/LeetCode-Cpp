/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        // 1. 数学归纳
        return n % 4 != 0;
    }
};
// @lc code=end

