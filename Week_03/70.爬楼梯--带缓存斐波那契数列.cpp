class Solution {
    int helper(vector<int>& steps, int n) {
        if (steps[n] > 0) return steps[n];
        steps[n] = helper(steps, n - 1) + helper(steps, n - 2);
        return steps[n];
    }
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> steps(n+1, 0);
        steps[1] = 1;
        steps[2] = 2;
        return helper(steps, n);
    }
};