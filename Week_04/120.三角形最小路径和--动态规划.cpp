/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (66.69%)
 * Likes:    618
 * Dislikes: 0
 * Total Accepted:    111.4K
 * Total Submissions: 167K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * 
 * 
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() < 1) return 0;
        int m = triangle.size();
        for (int i = 1; i < m; i++) {
            if (triangle[i].size() > 0)
                triangle[i][0] += triangle[i - 1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < triangle[i].size(); j++) {
                if (triangle[i-1].size() > j) {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
                else {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
            }
        }
        sort(triangle[m-1].begin(), triangle[m-1].end());
        return triangle[m-1][0];
    }
};
// @lc code=end

