class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pr;
        for(int i=0;i<position.size();i++){
            pr.push_back({position[i],speed[i]});
        }
        sort(pr.rbegin(),pr.rend());

        vector<double> st;
        for(auto &p:pr){
            st.push_back((double)(target-p.first)/p.second);
            if(st.size()>=2&&st.back()<=st[st.size()-2]){
                st.pop_back();
            }

        }
        return st.size();
    }
};
