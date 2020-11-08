/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (66.65%)
 * Likes:    679
 * Dislikes: 0
 * Total Accepted:    60.7K
 * Total Submissions: 91.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过填充空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * 提示：
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
class Solution {
    bool backtrace(vector<vector<char>>& board, unordered_map<int, int>& mp, int n) {
        int size = board.size();
        while (n < size*size && board[n/size][n%size] != '.') {
            ++n;
        }
        if (n >= size*size) return true;
        int x = n/size;
        int y = n%size;

        for (int j = 1; j <= size; j++) {
            int val1 = 100+x*10+j;
            int val2 = 200+y*10+j;
            int val3 = 300+(x/3*3+y/3)*10+j;
            if (mp[val1] != 1 && mp[val2] != 1 && mp[val3] != 1) {
                board[x][y] = '0' + j;
                mp[val1] = 1;
                mp[val2] = 1;
                mp[val3] = 1;
                if (backtrace(board, mp, n+1)) return true;
                board[x][y] = '.';
                mp[val1] = 0;
                mp[val2] = 0;
                mp[val3] = 0;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if (n < 1) return;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    mp[100+i*10+(board[i][j] - '0')] = 1;
                    mp[200+j*10+(board[i][j] - '0')] = 1;
                    mp[300+(i/3*3+j/3)*10+(board[i][j] - '0')] = 1;
                }
            }
        }
        backtrace(board, mp, 0);
    }
};
// @lc code=end

