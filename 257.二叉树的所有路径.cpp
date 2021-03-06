/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (57.82%)
 * Total Accepted:    8.3K
 * Total Submissions: 14.4K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例:
 *
 * 输入:
 *
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 *
 * 输出: ["1->2->5", "1->3"]
 *
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if (root) binaryTreePaths(root, v, "");
        return v;
    }
    void binaryTreePaths(TreeNode* root, vector<string> &v, string s) {
        if (!root) return;
        if (s.empty()) s += to_string(root->val);
        else s += ("->" + to_string(root->val));
        if (root->left || root->right) {
            binaryTreePaths(root->left, v, s);
            binaryTreePaths(root->right, v, s);
        } else {
            v.push_back(s);
        }
    }
};
