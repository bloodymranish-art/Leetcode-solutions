class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto x:nums){
            mp[x]++;
        }
        int n=nums.size();
        for(auto x:mp){
            if(x.second>(n/2)) ans=x.first;
        }
        return ans;
    }
};