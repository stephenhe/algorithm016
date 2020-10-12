/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 *
 * https://leetcode-cn.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Easy (37.94%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 31.4K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * 机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
 * 
 * 
 * -2：向左转 90 度
 * -1：向右转 90 度
 * 1 <= x <= 9：向前移动 x 个单位长度
 * 
 * 
 * 在网格上有一些格子被视为障碍物。
 * 
 * 第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
 * 
 * 机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
 * 
 * 返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: commands = [4,-1,3], obstacles = []
 * 输出: 25
 * 解释: 机器人将会到达 (3, 4)
 * 
 * 
 * 示例 2：
 * 
 * 输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * 输出: 65
 * 解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= commands.length <= 10000
 * 0 <= obstacles.length <= 10000
 * -30000 <= obstacle[i][0] <= 30000
 * -30000 <= obstacle[i][1] <= 30000
 * 答案保证小于 2 ^ 31
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int directionx[] = {0, 1, 0, -1};
        int directiony[] = {1, 0, -1, 0};
        int didx = 0;
        int x = 0; 
        int y = 0;
        int ans = 0;
        set<pair<int ,int>> ob_set;
        for (int m = 0; m < obstacles.size(); m++) {
            if (obstacles[m].size() > 1)
                ob_set.insert(pair(obstacles[m][0], obstacles[m][1]));
        }
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) {
                didx = (didx + 4 - 1) % 4;
            }
            else if (commands[i] == -1) {
                didx = (didx + 1) % 4;
            }
            else if (commands[i] >= 1 && commands[i] <= 9) {
                for (int j = 0; j < commands[i]; j++) {
                    int x_d = x + directionx[didx];
                    int y_d = y + directiony[didx];
                    if (ob_set.find(pair(x_d, y_d)) != ob_set.end()) {
                        break;
                    }
                    x = x_d;
                    y = y_d;
                    ans = max(ans, x*x+y*y);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

