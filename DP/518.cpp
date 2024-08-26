class Solution {
public:
    int change(int amount, vector<int>& coins) {    
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        // base case
        for (int i = 0; i <= n; i++) 
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                

                // 使用第 i 枚硬币的情况
                if (j - coins[i - 1] >= 0)
                    dp[i][j] = dp[i-1][j]+dp[i][j - coins[i - 1]];
                else
                    dp[i][j] = dp[i-1][j];
                    // 不使用第 i 枚硬币的情况
            }
        }

        return dp[n][amount];
    }    
};
