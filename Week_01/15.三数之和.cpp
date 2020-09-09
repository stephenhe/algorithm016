/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                return ret;

            int c = -nums[i];
            int first = i + 1;
            int second = nums.size() - 1;
            while (first < second) {
                if (nums[first] + nums[second] < c) {
                    first++;
                }
                else if (nums[first] + nums[second] > c) {
                    second--;
                }
                else {
                    // ret.push_back({nums[i], nums[first], nums[second]});
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[first];
                    triplet[2] = nums[second];
                    ret.push_back(triplet);

                    while (first < second && nums[first] == triplet[1]) first++;
                    while (first < second && nums[second] == triplet[2]) second--;
                    // vector<int> triplet(3, 0);
                    // triplet[0] = nums[i];
                    // triplet[1] = nums[first];
                    // triplet[2] = nums[second];
                    // ret.push_back(triplet);
                    
                    // // Processing duplicates of Number 2
                    // // Rolling the front pointer to the next different number forwards
                    // while (first < second && nums[first] == triplet[1]) first++;

                    // // Processing duplicates of Number 3
                    // // Rolling the back pointer to the next different number backwards
                    // while (first < second && nums[second] == triplet[2]) second--;
                }

            }

            while (i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        return ret;
    }
};
// @lc code=end

