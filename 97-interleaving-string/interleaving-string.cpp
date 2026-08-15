class Solution {
public:
    vector<vector<int>> dp;

    int rec(string &s1, string &s2, string &s3, int i, int j) {
        int k = i + j;

        if(k == s3.size())
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans1 = false;
        bool ans2 = false;

        if(i < s1.size() && s1[i] == s3[k]) {
            ans1 = rec(s1, s2, s3, i + 1, j);
        }

        if(j < s2.size() && s2[j] == s3[k]) {
            ans2 = rec(s1, s2, s3, i, j + 1);
        }

        return dp[i][j] = ans1 || ans2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size();
        int n = s2.size();

        dp.assign(m + 1, vector<int>(n + 1, -1));

        return rec(s1, s2, s3, 0, 0);
    }
};