/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
    vector<vector<int>> ret;
    vector<int> cur;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num = nums.size();
        for (int mask = 0; mask < (1 << num); mask++) {
            cur.clear();
            for (int i = 0; i < num; i++) {
                if (mask & (1 << i)) {
                    cur.push_back(nums[i]);
                }
            }
            ret.push_back(cur);
        }
        return ret;
    }
};
// @lc code=end

