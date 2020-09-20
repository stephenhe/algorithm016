class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        vector<int> steps(n+1, 0);
        steps[1] = 1;
        steps[2] = 2;
        for (int i = 3; i <= n; i++) {
            steps[i] = steps[i - 2] + steps[i - 1];
        }
        return steps[n];
    }
};