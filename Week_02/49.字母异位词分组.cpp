/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        int idx = 0;
        string tmp;
        unordered_map<string, int> nm;
        for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (nm.count(tmp)) {
                ret[nm[tmp]].push_back(strs[i]);
            }
            else {
                vector<string> st = vector(1, strs[i]);
                ret.push_back(st);
                nm[tmp] = idx++;
            }
        } 
        return ret;
    }
};
// @lc code=end

