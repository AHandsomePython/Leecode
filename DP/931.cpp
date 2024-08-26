class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
            res = min(res, dp(matrix, n - 1, j));
        }
        return res;
    }
    int dp(vector<vector<int>>& matrix, int i, int j) {
        // 非法索引检查
        if (i < 0 || j < 0 ||
            i >= matrix.size() ||
            j >= matrix[0].size()) {
            // 返回一个特殊值
            return 99999;
        }
        // base case
        if (i == 0) {
            return matrix[i][j];
        }
        // 状态转移
        return matrix[i][j] + min({
                dp(matrix, i - 1, j), 
                dp(matrix, i - 1, j - 1),
                dp(matrix, i - 1, j + 1)
            });
    }
};


// memo 


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int res = INT_MAX;
        // 备忘录里的值初始化为 66666
        vector<vector<int>> memo(n, vector<int>(n, 66666));
        // 终点可能在 matrix[n-1] 的任意一列
        for (int j = 0; j < n; j++) {
            res = min(res, dp(matrix, memo, n - 1, j));
        }
        return res;
    }

    int dp(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        // 1、索引合法性检查
        if (i < 0 || j < 0 ||
            i >= matrix.size() ||
            j >= matrix[0].size()) {
            
            return 99999;
        }
        // 2、base case
        if (i == 0) {
            return matrix[0][j];
        }
        // 3、查找备忘录，防止重复计算
        if (memo[i][j] != 66666) {
            return memo[i][j];
        }
        // 进行状态转移
        memo[i][j] = matrix[i][j] + min0(
                dp(matrix, memo, i - 1, j), 
                dp(matrix, memo, i - 1, j - 1),
                dp(matrix, memo, i - 1, j + 1)
            );

        return memo[i][j];
    }

    int min0(int a, int b, int c) {
        return min(a, min(b, c));
    }
};