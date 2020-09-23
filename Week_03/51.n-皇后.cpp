/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
    void helper(vector<vector<string>>& result, int n, int row, vector<int>& queens, unordered_set<int>& columns, unordered_set<int>& digastplus, unordered_set<int>& digastnegt) {
        if (row >= n) {
            vector<string> ret;
            for (int i = 0; i < n; i++) {
                string str(n, '.');
                if (queens[i] >= 0) {
                    str[queens[i]] = 'Q';
                }
                ret.push_back(str);
            }
            result.push_back(ret);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (columns.find(i) != columns.end()) continue;
            if (digastplus.find(row+i) != digastplus.end()) continue;
            if (digastnegt.find(row-i) != digastnegt.end()) continue;
            queens[row] = i;
            columns.insert(i); 
            digastplus.insert(row+i);
            digastnegt.insert(row-i);
            helper(result, n, row+1, queens, columns, digastplus, digastnegt);
            queens[row] = -1;
            columns.erase(i);
            digastplus.erase(row+i);
            digastnegt.erase(row-i);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens(n, -1);
        unordered_set<int> columns;
        unordered_set<int> digastplus;
        unordered_set<int> digastnegt;
        helper(result, n, 0, queens, columns, digastplus, digastnegt);
        return result;
    }
};
// @lc code=end

