class Solution {
public:
    vector<vector<int>> dp;

    int rec(string &s1, string &s2, int i, int j) {
        // Base cases
        if(j == s2.size())
            return s1.size() - i;

        if(i == s1.size())
            return s2.size() - j;

        if(dp[i][j] != -1)
            return dp[i][j];

        // No operation needed
        if(s1[i] == s2[j]) {
            return dp[i][j] = rec(s1, s2, i + 1, j + 1);
        }

        // Insert, Delete, Replace
        return dp[i][j] = 1 + min({
            rec(s1, s2, i, j + 1),       // insert
            rec(s1, s2, i + 1, j),       // delete
            rec(s1, s2, i + 1, j + 1)    // replace
        });
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        dp.assign(m, vector<int>(n, -1));

        return rec(word1, word2, 0, 0);
    }
};