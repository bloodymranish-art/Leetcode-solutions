class Solution {
public:
    static vector<int> findMissingElements(vector<int>& nums) {
        __uint128_t hasX = 0;
        int xMin = INT_MAX;
        int xMax = INT_MIN;

        for (int x : nums) {
            if (x >= 0 && x < 128)
                hasX |= ((__uint128_t)1 << x);

            xMin = min(xMin, x);
            xMax = max(xMax, x);
        }

        vector<int> ans;

        for (int x = xMin + 1; x < xMax; x++) {
            if (x >= 0 && x < 128 && ((hasX >> x) & 1) == 0)
                ans.push_back(x);
        }

        return ans;
    }
};