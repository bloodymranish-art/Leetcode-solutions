class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
       int i=0;
       int j=0; //nums2
       int k=0; //nums1
       vector<int> b(m+n);
       while(j<n && k<m)
       {
        if(nums1[k]<nums2[j])
        {
            b[i]=nums1[k];
            k++;
        }
        else
        {
            b[i]=nums2[j];
            j++;
        }
        i++;
       } 
       while(k<m)
       {
        b[i]=nums1[k];
        k++;
        i++;
       }
       while(j<n)
       {
        b[i]=nums2[j];
        j++;
        i++;
       }
       nums1=b;
    }
};