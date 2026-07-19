class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int kp=0;
             kp=nums[i]+ans[i-1];
            ans[i]=kp;
        }
        return ans;
    }
};