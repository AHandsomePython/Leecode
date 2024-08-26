class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // dp 数组全部初始化为 0
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        int start = 0;
        int maxLength = 1;
        // 反着遍历保证正确的状态转移
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                // 状态转移方程
                if (s[i] == s[j] && (j - i < 3 || dp[i+1][j-1] == 1)) {
                    dp[i][j] = 1;
                    if (j - i + 1 > maxLength) {
                        start = i;
                        maxLength = j - i + 1;
                    }
                } 
            }
        }
        return s.substr(start, maxLength);
    }
};