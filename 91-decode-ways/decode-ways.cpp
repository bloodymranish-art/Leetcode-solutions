class Solution {
public:
vector<int> dp;
int rec(int level,string &s){
    int n=s.size();
    //pruning
    if(level>n) return 0;
    if(level==n) return 1;
    if(dp[level]!=-1) return dp[level]; 
    int ans1=0;
    if(s[level]!='0'){
        ans1=rec(level+1,s);
    }
    int ans2=0;
    int num=(s[level]-'0')*10+(s[level+1]-'0');
    if(num>=10 && num<=26){
        ans2= rec(level+2,s);
    }
    return dp[level]= ans1+ans2;
}
    int numDecodings(string s) {
        int n= s.size();
        dp.assign(n+1,-1);
        return rec(0,s);
    }
};
