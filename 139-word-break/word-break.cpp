class Solution {
public:
    vector<int> dp;

    bool rec(string &s, unordered_set<string>& st, int level) {
        int n = s.size();

        if(level == n) return true;

        if(dp[level] != -1)
            return dp[level];

        for(int i = level; i < n; i++) {
            string temp = s.substr(level, i - level + 1);

            if(st.find(temp) != st.end()) {
                if(rec(s, st, i + 1))
                    return dp[level] = true;
            }
        }

        return dp[level] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;

        for(auto word : wordDict)
            st.insert(word);

        dp.assign(s.size(), -1);

        return rec(s, st, 0);
    }
};