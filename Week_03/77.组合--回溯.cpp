/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (74.62%)
 * Likes:    406
 * Dislikes: 0
 * Total Accepted:    107.4K
 * Total Submissions: 141.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution {
    void helper(vector<vector<int>>& result, vector<int>& ret, int n, int k, int count, int start, int end) {
        if (count == k) {
            result.push_back(ret);
            return;
        }

        for (int i = start; i <= end; i++) {
            if (find(ret.begin(), ret.end(), i) != ret.end()) continue;
            ret.push_back(i);
            helper(result, ret, n, k, count+1, i + 1, end + 1);
            ret.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> ret;
        helper(result, ret, n, k, 0, 1, n - k + 1);
        return result;
    }
};
// @lc code=end

