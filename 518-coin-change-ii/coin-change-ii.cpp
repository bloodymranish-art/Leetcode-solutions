class Solution {
public:
    vector<vector<int>> dp;

    int rec(int amount, vector<int>& coins, int level) {
        int n = coins.size();

        if(amount == 0) return 1;
        if(level == n) return 0;

        if(dp[amount][level] != -1)
            return dp[amount][level];

        int ans = 0;

        // Take current coin
        if(coins[level] <= amount) {
            ans += rec(amount - coins[level], coins, level);
        }

        // Skip current coin
        ans += rec(amount, coins, level + 1);

        return dp[amount][level] = ans;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        dp.assign(amount + 1, vector<int>(n, -1));

        return rec(amount, coins, 0);
    }
};