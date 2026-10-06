class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int time = 0;
        int fresh = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1)
                    fresh++;

                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        vector<pair<int,int>> dir = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };

        while(!q.empty() && fresh > 0) {

            int len = q.size();

            for(int i = 0; i < len; i++) {

                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for(auto &d : dir) {

                    int dr = r + d.first;
                    int dc = c + d.second;

                    if(dr >= 0 && dr < grid.size() &&
                       dc >= 0 && dc < grid[0].size() &&
                       grid[dr][dc] == 1) {

                        grid[dr][dc] = 2;
                        fresh--;

                        q.push({dr,dc});
                    }
                }
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};