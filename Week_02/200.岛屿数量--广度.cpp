/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int col_num = grid.size();
        if (col_num == 0) return 0;
        int row_num = grid[0].size();
        int ret = 0;
        for (int i = 0; i < col_num; i++) {
            for (int j = 0; j < row_num; j++) {
                if (grid[i][j] == '1') {
                    ret++;
                    queue<pair<int ,int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        int col = q.front().first;
                        int row = q.front().second;
                        q.pop();
                        grid[col][row] = '0';
                        if (col-1>=0 && grid[col-1][row] == '1') {
                            grid[col-1][row] = '0';
                            q.push({col-1, row});
                        }
                        if (col+1<col_num && grid[col+1][row] == '1') {
                            grid[col+1][row] = '0';
                            q.push({col+1, row});
                        }
                        if (row-1>=0 && grid[col][row-1] == '1') {
                            grid[col][row-1] = '0';
                            q.push({col, row-1});
                        }
                        if (row+1<row_num && grid[col][row+1] == '1') {
                            grid[col][row+1] = '0';
                            q.push({col, row+1});
                        }
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

