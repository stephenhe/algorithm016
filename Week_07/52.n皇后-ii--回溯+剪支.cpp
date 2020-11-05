/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
    void backtrace(vector<vector<string>>& result, vector<int>& queens, int n) {
        if (queens.size() == n) {
            string s = string(n, '.');
            vector<string> vec;
            for (int i = 0; i < queens.size(); i++) {
                vec.push_back(s);
                vec[i][queens[i]] = 'Q';
            }
            result.push_back(vec);
            return;
        }
        int qsize = queens.size();
        // 遍历整行
        for (int j = 0; j < n; j++) {
            bool find = false;
            for (int m = 0; m < qsize; m++) {
                // 横竖斜列都没有遇到皇后
                if (j == queens[m]
                || (qsize - j == m - queens[m]) 
                || (qsize + j == m + queens[m])) {
                    find = true;
                    break;
                }
            }
            if (find) continue;
            queens.push_back(j);
            backtrace(result, queens, n);
            queens.pop_back();
            
        } 
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> queens;
        backtrace(result, queens, n);
        return result;
    }
};
// @lc code=end

