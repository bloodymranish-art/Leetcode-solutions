class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double ans = (double)sum / k;

        for (int right = k; right < nums.size(); right++) {
            sum -= nums[right - k];  // remove outgoing element
            sum += nums[right];      // add incoming element

            ans = max(ans, (double)sum / k);
        }

        return ans;
    }
};