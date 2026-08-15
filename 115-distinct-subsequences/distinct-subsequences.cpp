class Solution {
public:
    vector<vector<int>> dp;

    int rec(string &s, string &t, int k, int level) {
        if(k == t.size())
            return 1;

        if(level == s.size())
            return 0;

        if(dp[level][k] != -1)
            return dp[level][k];

        int ans = 0;

        if(s[level] == t[k]) {
            ans = rec(s, t, k + 1, level + 1)
                + rec(s, t, k, level + 1);
        }
        else {
            ans = rec(s, t, k, level + 1);
        }

        return dp[level][k] = ans;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        dp.assign(m, vector<int>(n, -1));

        return rec(s, t, 0, 0);
    }
};