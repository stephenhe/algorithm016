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
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(int cur, int n, int k) {
        if ((tmp.size() + (n - cur + 1)) < k) return;
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, n, k);
        tmp.pop_back();
        dfs(cur + 1, n, k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};
// @lc code=end

