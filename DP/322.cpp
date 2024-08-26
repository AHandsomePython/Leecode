class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        int i,j;
        for (i=0;i<amount+1;i++){
            for (j=0;j<coins.size();j++){
                if (i-coins[j] < 0){
                    continue;
                }
                else{
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            } 
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};