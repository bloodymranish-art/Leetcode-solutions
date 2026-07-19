class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size());
        vector<int> suff(nums.size());
        suff[nums.size()-1]=nums[nums.size()-1];
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=nums[i]+pre[i-1];
        }
   for (int i = nums.size() - 2; i >= 0; i--) {
    suff[i] = nums[i] + suff[i + 1];
}
        for(int i=0;i<suff.size();i++){
            if(suff[i]==pre[i]) return i;
        }
        return -1;

    }
};