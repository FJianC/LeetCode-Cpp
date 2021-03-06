/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 *
 * https://leetcode-cn.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (47.76%)
 * Total Accepted:    52.1K
 * Total Submissions: 109.1K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 给定一个整数数组，判断是否存在重复元素。
 *
 * 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 *
 * 示例 1:
 *
 * 输入: [1,2,3,1]
 * 输出: true
 *
 * 示例 2:
 *
 * 输入: [1,2,3,4]
 * 输出: false
 *
 * 示例 3:
 *
 * 输入: [1,1,1,3,3,4,3,2,4,2]
 * 输出: true
 *
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int, int> m;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (m.find(nums[i]) != m.end()) m[nums[i]]++;
        //     else m[nums[i]] = 0;
        // }
        // unordered_map<int, int>::iterator it = m.begin();
        // while (it != m.end()) {
        //     if (it->second > 0) return true;
        //     ++it;
        // }
        // return false;
        return nums.size() > set<int>(nums.begin(), nums.end()).size(); 
    }
};
