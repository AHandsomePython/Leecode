class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        // i，j 初始化指向最后一个索引
        return dp(word1, m - 1, word2, n - 1);
    }
    // 定义：返回 s1[0..i] 和 s2[0..j] 的最小编辑距离
    int dp(string s1, int i, string s2, int j) {
        // base case
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;

        if (s1[i] == s2[j]) {
            return dp(s1, i - 1, s2, j - 1); // 啥都不做
        }
        return min0(
            dp(s1, i, s2, j - 1) + 1,    // 插入
            dp(s1, i - 1, s2, j) + 1,    // 删除
            dp(s1, i - 1, s2, j - 1) + 1 // 替换
        );
    }
    int min0(int a, int b, int c) {
        return min(min(a, b), c);
    }

};




class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min0(
                            dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + 1
                        );
                }
            }
        }
    // 储存着整个 s1 和 s2 的最小编辑距离
    return dp[m][n];
    }
    int min0(int a, int b, int c) {
        return min(a, min(b, c));
    }

};