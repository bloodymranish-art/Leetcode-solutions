class Solution {

public:
vector<vector<int>> dp;
int rec(int m,int n, int i, int j){
    if(i>m||j>n) return 0;
    if(i==m&&j==n) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    //computing
    return dp[i][j]=rec(m,n,i+1,j)+rec(m,n,i,j+1);

}
    int uniquePaths(int m, int n) {
 dp.assign(m, vector<int>(n, -1));
         return rec(m-1,n-1,0,0);
    }
};
