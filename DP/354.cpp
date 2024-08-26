class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(
            envelopes.begin(), 
            envelopes.end(), 
            [](const vector<int>& a, const vector<int>& b) -> bool {
                return a[0] == b[0] ? b[1] > a[1] : a[0] < b[0];
            }
        );
        vector<int> dp(envelopes.size(), 1);
        int i,j;
        for(i=0;i<envelopes.size();i++){
            for (j = i-1 ; j>=0;j--){
                if (envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        for (i=0;i<dp.size();i++){
            cout << envelopes[i][1] << endl;
        }
        for (i=0;i<dp.size();i++){
            cout << dp[i] << endl;
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;

    }
};



class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // 按宽度升序排列，如果宽度一样，则按高度降序排列
        sort(
            envelopes.begin(), 
            envelopes.end(), 
            [](const vector<int>& a, const vector<int>& b) -> bool {
                if (a[0] != b[0]) {
                    return a[0] < b[0]; // 宽度不同，按照宽度升序排序
                } else {
                    return b[1] < a[1]; // 宽度相同，按照高度降序排序
                }
            }
        );
        vector<int> dp(envelopes.size(), 1);
        int i,j;
        for(i=0;i<envelopes.size();i++){
            for (j = i-1 ; j>=0;j--){
                if (envelopes[j][1] < envelopes[i][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        // for (i=0;i<dp.size();i++){
        //     cout << envelopes[i][1] << endl;
        // }
        // for (i=0;i<dp.size();i++){
        //     cout << dp[i] << endl;
        // }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;

    }
};


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        vector<int> dp;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if (it == dp.end()) {
                dp.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }
        
        return dp.size();
    }
};
