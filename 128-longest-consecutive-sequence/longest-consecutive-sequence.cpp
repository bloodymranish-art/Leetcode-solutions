class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int maxi=1;
        int mini=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i]==nums[i-1]+1){
                mini++;
            }
            else{
                mini=1;
            }
           
            maxi=max(mini,maxi);
        }
        return maxi;
    }
};