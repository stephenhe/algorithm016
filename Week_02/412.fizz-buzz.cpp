/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i] = to_string(i+1);
        }
        for (int i = 2; i < n; i+=3) {
            ret[i] = "Fizz";
        }
        for (int i = 4; i < n; i+=5) {
            ret[i] = "Buzz";
        }
        for (int i = 14; i < n; i+=15) {
            ret[i] = "FizzBuzz";
        }
        return ret;
    }
};
// @lc code=end

