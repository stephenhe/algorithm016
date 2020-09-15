/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> num1_set(nums1.begin(), nums1.end());
        unordered_set<int> ret;
        for (auto num : nums2) {
            if (num1_set.find(num) != num1_set.end()) {
                ret.insert(num);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
};
// @lc code=end

