/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (42.25%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    76.8K
 * Total Submissions: 181.7K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

// @lc code=start
class Solution {
    class UnionFind {
    private:
        vector<int> parent;
    public:
        UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                parent.push_back(i);
            }
        }

        int find(int i) {
            int root = i;
            while (parent[root] != root) {
                root = parent[root];
            }
            return root;
        }

        void unite(int x, int y) {
            int rootx = find(x);
            int rooty = find(y);
            if (rootx != rooty) {
                parent[rootx] = rooty;
            }
        }
        
        bool isConnected(int x, int y) {
            return find(x) == find(y);
        }
    };
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m < 1) return;
        int n = board[0].size();
        UnionFind* uFind = new UnionFind(m*n+1);
        int dummy = m*n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                        uFind->unite(i*n+j, dummy);
                    }
                    else {
                        if (board[i-1][j] == 'O') uFind->unite(i*n+j, i*n+j-n);
                        if (board[i+1][j] == 'O') uFind->unite(i*n+j, i*n+j+n);
                        if (board[i][j-1] == 'O') uFind->unite(i*n+j, i*n+j-1);
                        if (board[i][j+1] == 'O') uFind->unite(i*n+j, i*n+j+1);
                    }
                }
            }
        }

        for (int i = 1; i < m-1; i++) {
            for (int j = 1; j < n-1; j++) {
                if (board[i][j] == 'O' && !uFind->isConnected(i*n+j, dummy)) {
                    board[i][j] = 'X';
                }
            }
        }

    }
};
// @lc code=end

