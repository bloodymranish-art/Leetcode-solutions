class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // adjacency list: {neighbor, weight}
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        // distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // {distance, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if (d > dist[node]) continue;

            for (auto &[next, wt] : adj[node]) {
                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};