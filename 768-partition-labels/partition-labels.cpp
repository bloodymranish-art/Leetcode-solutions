class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int st=0;
        int e=0;
        for(int i=0;i<s.size();i++){
            e=max(mp[s[i]],e);
            if(i==e){
                ans.push_back(e-st+1);
                  st=i+1;
            }
          
        }
        return ans;
        
    }
};