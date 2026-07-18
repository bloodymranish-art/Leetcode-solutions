class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N= grid.size();
        set<pair<int,int>> visit;
        priority_queue<vector<int>,vector<vector<int>>, greater<>> minh;
        vector<vector<int>> dir={
            {0,1},{0,-1},{1,0},{-1,0}
        };
        minh.push({grid[0][0],0,0});
        visit.insert({0,0});
        while(!minh.empty()){
            auto curr=minh.top();
            minh.pop();
            int t=curr[0],r=curr[1],c=curr[2];
            if(r==N-1&&c==N-1){
                return t;
            }
            for(auto& d:dir){
                int nr=r+d[0],nc=c+d[1];
                if(nr<0||nc<0||nc==N||nr==N||visit.count({nr,nc})){
                    continue;
                }
                visit.insert({nr,nc});
                minh.push({max(t,grid[nc][nr]),nr,nc});
            }
        }
        return N*N;

       
        // priority_queue< pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>pq;
    }
};
