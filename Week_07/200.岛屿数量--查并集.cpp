/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    class UnionFind {
    private:
        vector<int> parent;
        int count;
    public:
        UnionFind(vector<vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            count = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    parent.push_back(i*n+j);
                    if (grid[i][j] == '1')
                        ++count;
                }
            }
        }

        int find(int i) {
            int root = i;
            while (parent[root] != root) {
                root = parent[root];
            }
            // while (parent[i] != i) {
            //     int tmp = i;
            //     i = parent[i];
            //     parent[tmp] = root;
            // }
            return root;
        }

        void unite(int i, int j) {
            int rooti = find(i);
            int rootj = find(j);
            if (rooti != rootj) {
                parent[rootj] = rooti;
                --count;
            }
        }

        int getCount() const {
            return count;
        }
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n < 1) return 0;
        int m = grid[0].size();
        UnionFind* uFind = new UnionFind(grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && (grid[i-1][j] == '1' && grid[i][j] == '1'))
                    uFind->unite((i-1)*m+j, i*m+j);
                if (j > 0 && (grid[i][j-1] == '1' && grid[i][j] == '1'))
                    uFind->unite(i*m+j-1, i*m+j);
            }
        }
        return uFind->getCount();
    }
};
// @lc code=end

