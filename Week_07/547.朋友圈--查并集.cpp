/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 *
 * https://leetcode-cn.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (58.64%)
 * Likes:    355
 * Dislikes: 0
 * Total Accepted:    71.9K
 * Total Submissions: 122.4K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是
 * C 的朋友。所谓的朋友圈，是指所有朋友的集合。
 * 
 * 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j
 * 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * 输出：2 
 * 解释：已知学生 0 和学生 1 互为朋友，他们在一个朋友圈。
 * 第2个学生自己在一个朋友圈。所以返回 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * 输出：1
 * 解释：已知学生 0 和学生 1 互为朋友，学生 1 和学生 2 互为朋友，所以学生 0 和学生 2 也是朋友，所以他们三个在一个朋友圈，返回 1
 * 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 200
 * M[i][i] == 1
 * M[i][j] == M[j][i]
 * 
 * 
 */

// @lc code=start
class Solution {
    class UnionFind {
    private:
        vector<int> parent;
        int count;
    public:
        UnionFind(vector<vector<int>>& grid) {
            count = 0;
            int m = grid.size();
            if (m < 1) return;
            for (int i = 0; i < m; i++) {
                parent.push_back(i);
            }
            count = m;
        }

        int find(int i) {
            int root = i;
            while (parent[root] != root) {
                root = parent[root];
            }
            while (parent[i] != i) {
                int x = i;
                i = parent[i];
                parent[x] = root;
            }
            return root;
        }

        void unite(int x, int y) {
            int rootx = find(x);
            int rooty = find(y);
            if (rootx != rooty) {
                parent[rooty] = rootx;
                --count;
            }
        }

        int getCount() const {
            return count;
        }
    };
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() < 1) return 0;
        UnionFind* uFind = new UnionFind(M);
        for (int i = 0; i < M.size(); i++) {
            for (int j = i+1; j < M.size(); j++) {
                if (M[i][j] == 1)
                    uFind->unite(i, j);
            }
        }
        return uFind->getCount();
    }
};
// @lc code=end

