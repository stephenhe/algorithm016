学习笔记
不同路径 2 状态转移方程
dp[i][j] = obstacleGrid[i][j]==0?((i>0?dp[i-1][j]:0) + (j>0?dp[i][j-1]:0)):0;