/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> deq;
        for (int i = 0; i < nums.size(); i++) {
            // 弹出小的元素
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            // 弹出不在窗口内的元素
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();

            // 压入当前元素
            deq.push_back(i);

            // 到k个元素开始取结果
            if (i > k - 2) {
                ret.push_back(nums[deq.front()]);
            }
        }
        return ret;
    }
};
// @lc code=end

