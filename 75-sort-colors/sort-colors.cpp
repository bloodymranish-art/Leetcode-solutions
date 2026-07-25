class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt1++;
            if(nums[i]==1) cnt2++;
            if(nums[i]==2) cnt3++;
        }
        int i=0;
    while(i<nums.size() ){
       while(cnt1) {nums[i]=0;
       cnt1--;
       i++;
       }
        while(cnt2){nums[i++]=1;
        cnt2--;
        }

        while(cnt3){ nums[i++]=2;
        cnt3--;
        }
    }
    } 
};