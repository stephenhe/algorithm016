class Solution {
    int helper(unordered_map<int, int>& map, int n) {
        if (n == 0) {
            map[0] = 1;
        }
        if (n == 1) {
            map[1] = 1;
        }
        if (map.find(n) != map.end()) {
            return map[n];
        }
        map[n] = helper(map, n - 1) + helper(map, n - 2);

        return map[n];
    }
public:
    int climbStairs(int n) {
        unordered_map<int, int> steps_map;
        return helper(steps_map, n);
    }
};