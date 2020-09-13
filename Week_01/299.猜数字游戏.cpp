/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        int b = 0;
        unordered_map<char, int> mymap;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) ++a;
            ++mymap[secret[i]];
        }
        for (int i = 0; i < guess.length(); i++) {
            if (mymap[guess[i]] > 0) {
                ++b;
                --mymap[guess[i]];
            }
        }
        b -= a;
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
// @lc code=end

