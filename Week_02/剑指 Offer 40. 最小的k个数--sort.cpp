/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ret;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k && i < arr.size(); i++) {
            ret.push_back(arr[i]);
        }
        return ret;
    }
};
// @lc code=end

