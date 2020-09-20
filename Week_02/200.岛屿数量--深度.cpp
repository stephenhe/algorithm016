/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int col_num = grid.size();
        int row_num = grid[0].size();

        grid[c][r] = '0';
        if (r-1>=0 && grid[c][r-1] == '1') dfs(grid, r-1, c);
        if (r+1<row_num && grid[c][r+1] == '1') dfs(grid, r+1, c);
        if (c-1>=0 && grid[c-1][r] == '1') dfs(grid, r, c-1);
        if (c+1<col_num && grid[c+1][r] == '1') dfs(grid, r, c+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int ret = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    ret++;
                    dfs(grid, j, i);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

