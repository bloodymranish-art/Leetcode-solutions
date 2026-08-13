class Solution {
public:
    vector<vector<vector<int>>> dp;

    int rec(vector<int>& prices, int level, bool holding, bool done) {
        int n = prices.size();

        if(level == n) {
            if(holding) return -1e9;
            return 0;
        }

        if(dp[level][holding][done] != -1)
            return dp[level][holding][done];

        if(done)
            return dp[level][holding][done] = 0;

        if(!holding) {
            return dp[level][holding][done] = max(
                rec(prices, level + 1, true, false) - prices[level],
                rec(prices, level + 1, false, false)
            );
        }

        return dp[level][holding][done] = max(
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