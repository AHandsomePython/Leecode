class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dp(s,0,wordDict);
    }

    bool dp(string s, int i, vector<string>& wordDict){
        if (i == s.length()) {
            return true;
        }
        int j;
        for (j=0;j<wordDict.size();j++){
            if (s.substr(i, wordDict[j].length()) == wordDict[j]) {
                int len =wordDict[j].length();
                // 只要 s[i+len..] 可以被拼出，s[i..] 就能被拼出
                if (dp(s, i + len, wordDict) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dp(s,0,wordDict);
    }

    bool dp(string s, int i, vector<string>& wordDict){
        if (i == s.length()) {
            return true;
        }
        int j;
        for (j=0;j<wordDict.size();j++){
            if (s.substr(i, wordDict[j].length()) == wordDict[j]) {
                int len =wordDict[j].length();
                // 只要 s[i+len..] 可以被拼出，s[i..] 就能被拼出
                if (dp(s, i + len, wordDict) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};



// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

class Solution {
private:
    // 用哈希集合方便快速判断是否存在
    unordered_set<string> wordDict;
    // 备忘录，-1 代表未计算，0 代表无法凑出，1 代表可以凑出
    vector<int> memo;

public:
    // 主函数
    bool wordBreak(string s, vector<string>& wordDict) {
        // 转化为哈希集合，快速判断元素是否存在
        for (auto word : wordDict) {
            this->wordDict.insert(word);
        }
        // 备忘录初始化为 -1
        memo.resize(s.length(), -1);
        return dp(s, 0);
    }

    // 定义：s[i..] 是否能够被拼出
    bool dp(const string& s, int i) {
        // base case
        if (i == s.length()) {
            return true;
        }
        // 防止冗余计算
        if (memo[i] != -1) {
            return memo[i] == 0 ? false : true;
        }

        // 遍历 s[i..] 的所有前缀
        for (int len = 1; i + len <= s.length(); len++) {
            // 看看哪些前缀存在 wordDict 中
            string prefix = s.substr(i, len);
            if (wordDict.count(prefix)) {
                // 找到一个单词匹配 s[i..i+len)
                // 只要 s[i+len..] 可以被拼出，s[i..] 就能被拼出
                bool subProblem = dp(s, i + len);
                if (subProblem == true) {
                    memo[i] = 1;
                    return true;
                }
            }
        }
        // s[i..] 无法被拼出
        memo[i] = 0;
        return false;
    }
};



