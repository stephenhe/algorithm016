class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int first = 1;
        int second = 2;
        for (int i = 2; i < n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};