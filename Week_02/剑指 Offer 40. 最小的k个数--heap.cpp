/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k > arr.size()) return arr;
        vector<int> ret;
        if (k <= 0) return ret;
        priority_queue<int> pq;
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (pq.top() > arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};// @lc code=end

