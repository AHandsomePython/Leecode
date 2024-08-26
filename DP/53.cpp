class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1;i<n;i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
        }
        int res = INT_MIN;
        for (int i=0;i<n;i++){
            if (res < dp[i]){
                res = dp[i];
            }
        }
        return res;
    }
};