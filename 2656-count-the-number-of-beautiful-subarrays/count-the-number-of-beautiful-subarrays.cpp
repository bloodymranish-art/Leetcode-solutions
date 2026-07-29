class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> mp;

        long long ans = 0;
        int xr = 0;

        mp[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            xr ^= nums[i];

            if (mp.find(xr) != mp.end()) {
                ans += mp[xr];
            }

            mp[xr]++;
        }

        return ans;
    }
};