class Solution {
public:
    vector<vector<vector<int>>> dp;

    int rec(vector<int>& prices, int level, bool sell, bool cooldown) {
        int n = prices.size();

        if(level == n) {
            if(sell) return -1e9;
            return 0;
        }

        if(dp[level][sell][cooldown] != -1)
            return dp[level][sell][cooldown];

        if(cooldown) {
            return dp[level][sell][cooldown] =
                rec(prices, level + 1, false, false);
        }

        if(!sell) {
            return dp[level][sell][cooldown] = max(
                rec(prices, level + 1, true, false) - prices[level],
                rec(prices, level + 1, false, false)
            );
        }

        return dp[level][sell][cooldown] = max(
            rec(prices, level + 1, false, true) + prices[level],
            rec(prices, level + 1, true, false)
        );
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.assign(n, vector<vector<int>>(
            2, vector<int>(2, -1)
        ));

        return rec(prices, 0, false, false);
    }
};